/* Just an example firmware that displays Pixl is the best ysws, I used AI for parts of this, and didnt count this in journals,hackatime*/
#include "stm32g0xx_hal.h"
#include <string.h>
#include <stdint.h>

#define EPAPER_WIDTH   800
#define EPAPER_HEIGHT  480

#define CS_LOW()    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET)
#define CS_HIGH()   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET)
#define DC_CMD()    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET)
#define DC_DATA()   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET)
#define RST_LOW()   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET)
#define RST_HIGH()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET)
#define BUSY()      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)

SPI_HandleTypeDef hspi1;
static uint8_t fb[(EPAPER_WIDTH / 8) * EPAPER_HEIGHT];

typedef struct { char c; uint8_t b[8]; } glyph_t;

static const glyph_t font[] = {
 {' ',{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 {'!',{0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x00}},
 {'P',{0x7C,0x66,0x66,0x7C,0x60,0x60,0x60,0x00}},
 {'S',{0x3C,0x66,0x60,0x3C,0x06,0x66,0x3C,0x00}},
 {'W',{0x66,0x66,0x66,0x6E,0x76,0x66,0x66,0x00}},
 {'Y',{0x66,0x66,0x3C,0x18,0x18,0x18,0x18,0x00}},
 {'b',{0x60,0x60,0x7C,0x66,0x66,0x66,0x7C,0x00}},
 {'e',{0x00,0x3C,0x66,0x7E,0x60,0x60,0x3C,0x00}},
 {'h',{0x60,0x60,0x7C,0x66,0x66,0x66,0x66,0x00}},
 {'i',{0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00}},
 {'l',{0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00}},
 {'s',{0x00,0x3C,0x60,0x3C,0x06,0x06,0x3C,0x00}},
 {'t',{0x18,0x18,0x7E,0x18,0x18,0x18,0x0E,0x00}},
 {'x',{0x00,0x00,0x66,0x3C,0x18,0x3C,0x66,0x00}},
};

void SystemClock_Config(void);
void MX_GPIO_Init(void);

static void wr_byte(uint8_t b) {
    HAL_SPI_Transmit(&hspi1, &b, 1, HAL_MAX_DELAY);
}

static void cmd(uint8_t c) {
    DC_CMD();  CS_LOW();
    wr_byte(c);
    CS_HIGH();
}

static void data(uint8_t d) {
    DC_DATA(); CS_LOW();
    wr_byte(d);
    CS_HIGH();
}

static void wait_busy(void) {
    uint32_t t0 = HAL_GetTick();
    while (BUSY() == GPIO_PIN_SET) {
        if (HAL_GetTick() - t0 > 30000) break;
    }
}

static void epaper_init(void) {
    RST_LOW();  HAL_Delay(20);
    RST_HIGH(); HAL_Delay(20);
    cmd(0x12);  HAL_Delay(20); wait_busy();
    cmd(0x01);
    data(0x07); data(0x07); data(0x3F); data(0x3F);
    cmd(0x04); wait_busy();
    cmd(0x00); data(0x1F);
    cmd(0x61);
    data(0x03); data(0x20);
    data(0x01); data(0xE0);
    cmd(0x15); data(0x00);
    cmd(0x50); data(0x10); data(0x07);
    cmd(0x60); data(0x22);
    cmd(0x82); data(0x08);
    HAL_Delay(50);
}

static void epaper_clear(uint8_t color) {
    memset(fb, color, sizeof(fb));
}

static void pixel(uint16_t x, uint16_t y, uint8_t on) {
    if (x >= EPAPER_WIDTH || y >= EPAPER_HEIGHT) return;
    uint32_t i = (uint32_t)y * (EPAPER_WIDTH / 8) + (x >> 3);
    uint8_t  m = 0x80 >> (x & 7);
    if (on) fb[i] &= ~m;
    else    fb[i] |=  m;
}

static const glyph_t *find(char c) {
    for (unsigned i = 0; i < sizeof(font)/sizeof(font[0]); i++)
        if (font[i].c == c) return &font[i];
    return &font[0];
}

static void epaper_draw_string(uint16_t x, uint16_t y,
                               const char *s, uint8_t scale) {
    while (*s) {
        const glyph_t *g = find(*s++);
        for (uint8_t row = 0; row < 8; row++) {
            for (uint8_t col = 0; col < 8; col++) {
                if (g->b[row] & (0x80 >> col)) {
                    for (uint8_t sy = 0; sy < scale; sy++)
                        for (uint8_t sx = 0; sx < scale; sx++)
                            pixel(x + col*scale + sx,
                                  y + row*scale + sy, 1);
                }
            }
        }
        x += 8 * scale;
    }
}

static void epaper_refresh(void) {
    cmd(0x44);
    data(0x00); data((EPAPER_WIDTH/8) - 1);
    cmd(0x45);
    data(0x00); data(0x00);
    data((EPAPER_HEIGHT-1) & 0xFF); data((EPAPER_HEIGHT-1) >> 8);
    cmd(0x4E); data(0x00);
    cmd(0x4F); data(0x00); data(0x00);
    cmd(0x24);
    DC_DATA(); CS_LOW();
    HAL_SPI_Transmit(&hspi1, fb, sizeof(fb), HAL_MAX_DELAY);
    CS_HIGH();
    cmd(0x22); data(0xF7);
    cmd(0x20); wait_busy();
    cmd(0x02); wait_busy();
}

static void epaper_sleep(void) {
    cmd(0x07); data(0xA5);
}

static void MX_SPI1_Init(void)
{
    hspi1.Instance               = SPI1;
    hspi1.Init.Mode              = SPI_MODE_MASTER;
    hspi1.Init.Direction         = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize          = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity       = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase          = SPI_PHASE_1EDGE;
    hspi1.Init.NSS               = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
    hspi1.Init.FirstBit          = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode            = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial     = 7;
    HAL_SPI_Init(&hspi1);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_SPI1_Init();

    HAL_Delay(500);

    epaper_init();
    epaper_clear(0xFF);

    const char *msg = "Pixl is the best YSWS!!";
    uint8_t  scale  = (EPAPER_WIDTH >= 800) ? 4 : 2;
    uint16_t n      = strlen(msg);
    uint16_t tw     = n * 8 * scale;
    uint16_t th     = 8 * scale;
    uint16_t x      = (EPAPER_WIDTH  - tw) / 2;
    uint16_t y      = (EPAPER_HEIGHT - th) / 2;

    epaper_draw_string(x, y, msg, scale);
    epaper_refresh();
    epaper_sleep();

    while (1) {
        HAL_Delay(1000);
    }
}
