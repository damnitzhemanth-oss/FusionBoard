# FusionBoard 

(*As this is for nerds, I used AI to format and use technical words*)

## 1. Board Overview

| Item | Specification |
|---|---|
| Board name | FusionBoard Devboard |
| Main SoC | AMD/Xilinx Zynq UltraScale+ XCZU4EV |
| SoC package | FBVB900, 900-pin |
| Management MCU | STM32G0B1RBT6, Arm Cortex-M0+, 64 MHz, 128 KB flash, 144 KB RAM, LQFP-64 |
| Main memory | 4× Micron MT40A512M16LY-075:E DDR4, FBGA-96 |
| DDR4 capacity | 4 GB total, 64-bit bus |
| Boot/config memory | Micron MT25QU256ABA8ESF-0SIT, 256 Mb QSPI NOR, SOP-16 |
| Mass storage | FORESEE FEMDNN032G-A3A55, 32 GB eMMC, FBGA-153 |
| Removable storage | TF-01A microSD socket |
| Ethernet | DP83867IRRGZR GbE PHY + HR911105A RJ45 with magnetics |
| USB | USB3320C ULPI PHY, USB2514B 4-port USB 2.0 hub, CP2102N USB-UART |
| High-speed | PCIe x1 edge connector, SFP+ cage, USB 3.0 Type-C, DisplayPort over USB-C |
| Analog/RF | LMX2594 RF PLL, ADS4245 dual 14-bit ADC, ADS131M08 8-ch 24-bit ADC, AD9744 14-bit DAC, ADL8100 LNA, 310–400 MHz BPF |
| Sensors | TMP117, ICM-42688-P, MMC5983MA, BMP581, MAX-M10S GNSS |
| Security | ATECC608B secure element + OPTIGA TPM SLB 9673 FW26 |
| Power input | DC jack, USB-C PD, XT60 battery, energy harvester |
| Battery management | BQ25895 charger, BQ27441-G1A fuel gauge, DW06 protection |
| Harvester | BQ25570 nano-power harvester + 22 F supercapacitor |
| Display | ePaper SPI header |
| Expansion | Multiple 1×10 headers, JTAG, fan, I2C, BMC headers |

---

## 2. Hierarchical Sheet Map

The schematic is split into 17 sheets:

| Sheet | Name |
|---:|---|
| 1 | `/` |
| 2 | `/Power,Input,Protection/` |
| 3 | `/Battery.Charger,Fuel Gauge/` |
| 4 | `/Power Tree/` |
| 5 | `/Zynq Section/` |
| 6 | `/Zynq Section/Zynq CORE/` |
| 7 | `/Zynq Section/DDR4 Memory/` |
| 8 | `/Zynq Section/Peripherals/` |
| 9 | `/Zynq Section/High Speed Peripherals/` |
| 10 | `/Clocking/` |
| 11 | `/Video/` |
| 12 | `/Analog_RF/` |
| 13 | `/Sensors and GNSS/` |
| 14 | `/RTC & Security/` |
| 15 | `/Harvester, BMC, Telemetry/` |
| 16 | `/ePaper Ink Display/` |
| 17 | `/Expansion/` |

---

## 3. Core SoC and Memory Subsystem

### 3.1 Main SoC

| Parameter | Specification |
|---|---|
| Part | `xczu4evfbvb900pkg` |
| Family | AMD/Xilinx Zynq UltraScale+ |
| Device | XCZU4EV |
| Package | FBVB900, 900-pin |
| PS interfaces used | DDR4, QSPI, SD/eMMC, GEM Ethernet, USB, UART, I2C, SPI, JTAG, GPIO |
| PL banks | VCCO 45, 46, 64, 65, 66 |
| PS-GTR | USB3, PCIe, DisplayPort |
| GTH | SFP+, expansion high-speed lanes |

### 3.2 DDR4 Memory

| Parameter | Specification |
|---|---|
| Devices | 4× `MT40A512M16LY-075:E` |
| Type | DDR4 SDRAM, x16 |
| Total capacity | 4 GB |
| Bus width | 64-bit |
| Package | FBGA-96 |
| Speed grade | `-075:E` as exported |
| Reference rails | `+1V2`, `VREFCA_DDR4`, `+2V5` for VPP |
| Termination | 240 Ω ZQ resistors per device; VREF divider/RC |

### 3.3 Non-Volatile Memory

| Device | Type | Capacity | Interface |
|---|---|---|---|
| `MT25QU256ABA8ESF-0SIT` | QSPI NOR flash | 256 Mb / 32 MB | QSPI |
| `FEMDNN032G-A3A55` | eMMC | 32 GB | eMMC |
| `TF-01A` | microSD socket | User card | SDIO / SPI-capable |

### 3.4 Boot / Configuration Signals

Exported boot and configuration signals include:

- `QSPI_IO0..IO3`, `QSPI_SCLK`, `QSPI_SS`
- `SD0_*`, `SD1_*`
- `PS_POR_B`, `PS_PROG_B`, `PS_DONE`, `PS_INIT_B`
- `PS_MODE0..3`
- `PS_JTAG_TCK/TDI/TDO/TMS`
- `PS_ERROR_OUT`, `PS_ERROR_STATUS`

---

## 4. Power Input and Protection

### 4.1 Input Sources

| Source | Connector/Part | Notes |
|---|---|---|
| DC jack | `PJ-102AH` / `DC1` | Barrel DC input |
| USB-C | `TYPE-C-24P-SMD` / `USB1` | USB-C PD sink |
| USB-C PD controller | `STUSB4500QTR` / `U2` | USB Power Delivery sink controller |
| Battery | `XT60` / `U7` | Main battery pack input |
| Energy harvester | `BQ25570` | Harvesting input |

### 4.2 Protection and Power Path

| Ref | Part | Function |
|---|---|---|
| `U1` | `TPD6S300ARUKR` | USB-C ESD/CC protection |
| `U3` | `TVS2201DRBR` | VBUS surge/TVS protection |
| `U4`, `U6` | `TPS259470ARPWR` | eFuse / hot-swap protection |
| `U5` | `TPS2121RUXR` | Power mux / source priority |
| `U11` | `LM66100DCK` | Ideal diode / reverse-polarity protection |
| `D1` | `SMBJ20A` | TVS |
| `D3` | `TP7.OSMD24CA-XC` | TVS |
| `D4` | `LSMB24CAH` | TVS |
| `D7`, `D8` | Schottky | OR-ing / reverse protection |

### 4.3 USB-C PD

| Parameter | Specification |
|---|---|
| Controller | `STUSB4500QTR` |
| Interface | I2C |
| Signals | `CC1`, `CC2`, `ALERT`, `ATTACH`, `SINK_SCL`, `SINK_SDA` |
| VBUS discharge | `VBUS_VS_DISCH` |
| Power path | VBUS → protection → eFuse → power mux |

---

## 5. Battery Charger and Fuel Gauge

| Ref | Part | Function |
|---|---|---|
| `U9` | `BQ25895RTWR` | Switch-mode battery charger with power path, I2C |
| `U10` | `BQ27441DRZR-G1A` | Fuel gauge / battery monitor, I2C |
| `U8` | `DW06` | Battery protection IC |
| `U7` | `XT60` | Battery connector |
| `R33` | `10 mΩ` | Current shunt for fuel gauge |
| `RT1` | `10 kΩ NTC` | Battery temperature sense |
| `SW1` | `SW_Push` | QON / push-button input |
| `D9` | Green LED | Charger status |
| `D5`, `D6` | Red/Green LEDs | Power/status indication |

Charger-related nets include:

- `BATT_CHG`
- `RAW_BAT`
- `CELL_B+`
- `CELL_B-`
- `PACK_P-`
- `CHG_STAT_N`
- `CHG_EN_N`
- `FuelGauge_SCL`
- `FuelGauge_SDA`
- `BQ_INT_N`

---

## 6. Power Tree and Regulators

### 6.1 Exported Voltage Rails

The design exports these rails:

- `+0V85`
- `+0V85_GTR`
- `+0V85_PS`
- `+0V9_GTR`
- `+0V9_VCU`
- `+0V9_VCU_GT`
- `+1V2`
- `+1V2_GTH`
- `+1V2_PS`
- `+1V8`
- `+1V8_CLEAN`
- `+1V8_MGTRAVTT`
- `+1V8_VCCADC`
- `+1V25`
- `+2V5`
- `+3V3`
- `+3V3_ANA`
- `+3V3_BMC`
- `+3V3_HARVEST`
- `+3V3_LMX`
- `+5V_ANA`
- `+5V_BOOST`
- `+5V_SYS`
- `+15V_MAIN`
- `+VSYS`
- `VREG_2V7`
- `VIN_DC`
- `RAW_BAT`
- `OUT_VBUS`

### 6.2 Regulator Inventory

| Ref | Part | Type | Exported role |
|---|---|---|---|
| `U13` | `TPS548A20RVER` | Synchronous buck | Core/low-voltage rail, output via `L4` |
| `U14` | `TPS62130RGTR` | Buck | 3.3 V class rail, output via `L3` |
| `U15` | `TPS54824RNVR` | Buck | 5 V system rail, output via `L5` |
| `U16` | `TPS62823DLCR` | Buck | Low-voltage rail, output via `L6` |
| `U17` | `TPS62822DLCR` | Buck | Low-voltage rail, output via `L7` |
| `U18` | `TPS7A4700RGWR` | LDO | Low-noise analog rail |
| `U19` | `TPS3700DSET` | Voltage supervisor | Power-good / UV/OV monitor |
| `U20` | `TPS54824RNVR` | Buck | Rail via `L8` |
| `U21` | `TPS54824RNVR` | Buck | Rail via `L9` |
| `U22` | `TPS7A4700RGWR` | LDO | 2.5 V rail |
| `U23` | `TPS7A4700RGWR` | LDO | 1.8 V clean rail |
| `U24` | `RS3112-1.25XSF3` | LDO/reference | 1.25 V rail |
| `U25` | `TPS54824RNVR` | Buck | Rail via `L10` |
| `U26` | `TPS7A4700RGWR` | LDO | 5 V analog rail via ferrite `FB7` |
| `U12` | `TPS61088RHLR` | Boost | 5 V boost rail |
| `U11` | `LM66100DCK` | Ideal diode | 5 V OR-ing |

Inductors:

- `L3`: 1/2.2 µH
- `L4`: 0.47 µH, 15 A
- `L5`: 10 µH, 12 A
- `L6`–`L10`: 1–2.2 µH range

Ferrite beads:

- `FB1`–`FB10`: 120 Ω @ 100 MHz, used for rail filtering

---

## 7. Clocking and Timing

| Ref | Part | Frequency / Function | Destination |
|---|---|---|---|
| `U41` | `SI5341A-D12636-GM` | Clock generator / jitter attenuator, 10 outputs | PS reference, ADC, DAC, Ethernet, USB |
| `Y5` | `ECS_480-8-37-A-D-P-TR` | 48 MHz crystal | SI5341 reference |
| `Y4` | `SiT9365AI-4B2-33E100.0000000` | 100.000 MHz differential oscillator | PCIe reference clock |
| `Y6` | `SiT5356AI-FP-25VT-16.367667` | 16.367667 MHz TCXO | LMX2594 RF PLL |
| `Y7` | 25 MHz crystal | 25 MHz | ADS131M08 |
| `Y2` | 25 MHz crystal | 25 MHz | DP83867 Ethernet PHY |
| `Y3` | 26 MHz crystal | 26 MHz | USB2514 hub |
| `Y1` | 25 MHz crystal | 25 MHz | USB3320/USB reference |

SI5341 exported outputs:

- `OUT0` → `PS_REF_CLK`
- `OUT1` → `CLOCK_ADC`
- `OUT2` → `DAF_CLK`
- `OUT4` → `E_XI` Ethernet PHY clock
- `OUT5` → `USB_REFCLK`

---

## 8. High-Speed Interfaces and Transceivers

### 8.1 PS-GTR Usage

| Lane / Signal | Exported Use |
|---|---|
| PS-GTR lane 0 | USB 3.0 SuperSpeed TX/RX |
| PS-GTR lane 1 | PCIe x1 TX/RX |
| PS-GTR lane 2 | DisplayPort TX0 over USB-C |
| PS-GTR reference clocks | `PS_REFCLK0_100M`, `PS_REFCLK1_27M` |

### 8.2 GTH Usage

| GTH Quad / Lane | Exported Use |
|---|---|
| GTH 226 lane 0 | SFP+ TX/RX |
| GTH 226 lane 1 | Expansion high-speed lane 0 |
| GTH 226 lane 2 | Expansion high-speed lane 1 |
| GTH 226 lane 3 | Expansion high-speed lane 2 |
| GTH 225 lane 0 | Expansion high-speed lane 3 |
| GTH 225 lane 1 | Expansion high-speed lane 4 |
| Other GTH lanes | Exported as unconnected |

### 8.3 High-Speed Connectors

| Connector | Part | Function |
|---|---|---|
| `CN1` | `1-2199230-6` | PCIe edge connector, x1 lane |
| `J12` | `SFP+` cage | SFP+ optical transceiver |
| `USB3` | `TYPE-C-24P-SMD` | USB 3.0 / high-speed Type-C |
| `USB4` | `472720001` | USB-C / DisplayPort alternate-mode connector |
| `J3` | `USB3_B` | USB 3.0 B-style connector / downstream USB |

---

## 9. Peripherals and Connectivity

### 9.1 Ethernet

| Item | Specification |
|---|---|
| PHY | `DP83867IRRGZR` |
| MAC interface | RGMII to Zynq PS GEM |
| Connector | `HR911105A` RJ45 with integrated magnetics |
| Management | MDIO/MDC |
| Reset | `GEM_RST` from PS MIO |
| Clock | 25 MHz crystal `Y2` |

### 9.2 USB

| Item | Specification |
|---|---|
| USB 2.0 PHY | `USB3320C-EZK-TR`, ULPI |
| USB hub | `USB2514B_Bi`, 4-port USB 2.0 hub |
| USB-UART | `CP2102N-A02-GQFN24` |
| ESD | `TPD4E05U06DQA` |
| Connectors | Multiple `TYPE-C-24P-SMD`, `USB3_B`, Molex `472720001` |
| VBUS sensing | `USB3_VBUS`, `USB3_VBUS_NET` |
| ULPI signals | `USB2_CLK`, `USB2_D0..D7`, `USB2_DIR`, `USB2_NXT`, `USB2_STP` |

### 9.3 Storage and Card Interfaces

- QSPI NOR: `MT25QU256ABA8ESF-0SIT`
- eMMC: `FEMDNN032G-A3A55`
- microSD: `TF-01A`
- SD0 8-bit interface to eMMC
- SD1 4-bit interface to microSD via `TXS02612RTWR` level shifter/mux

### 9.4 Camera / Video

| Item | Specification |
|---|---|
| Connector | `J13`, 22-pin FFC/FPC |
| Interface | MIPI CSI-2: `MIPI_CLK_P/N`, `MIPI_D0..D3_P/N` |
| Control | `CAM_PWDN`, `CAM_RST_N`, I2C |
| Power | `+3V3`, `+1V8` |

### 9.5 ePaper

| Item | Specification |
|---|---|
| Connector | `J8`, 1×09 pin header |
| Interface | SPI: `EPD_SCK`, `EPD_MOSI`, `EPD_MISO`, `EPD_CS`, `EPD_DC`, `EPD_RST`, `EPD_BUSY` |
| Controller | STM32G0B1 BMC |

### 9.6 Fan and Debug

- Fan header `J11`, 1×04: `FAN_TACH`, PWM/control, power, GND
- JTAG `J10`, 2×07: `PS_JTAG_TCK/TDI/TDO/TMS`, `PS_SRST_B`
- I2C header `J6`, 1×02: `3.3V_I2C`

---

## 10. Analog / RF Subsystem

### 10.1 RF Signal Chain

| Ref | Part | Function |
|---|---|---|
| `U43` | `LMX2594RHAR` | Wideband RF PLL / synthesizer with integrated VCO |
| `Y6` | `SiT5356AI-FP-25VT-16.367667` | 16.367667 MHz precision TCXO |
| `SW2` | RF switch, LFCSP-16 | RF path switching |
| `U48` | `ADL8100ACPZN` | RF low-noise amplifier |
| `U49` | `BPF-A355` | Bandpass filter, 310–400 MHz, 50 Ω |
| `J9` | SMA coaxial connector | RF input/output |
| `U42` | `REF5025AD` | 2.5 V precision voltage reference |
| `U47` | `THS4509RGTT` | Differential amplifier / ADC driver |
| `U45` | `ADS4245IRGCT` | Dual 14-bit ADC, LVDS outputs |
| `U44` | `ADS131M08IPBS` | 8-channel, 24-bit delta-sigma ADC, SPI |
| `U46` | `AD9744ARUZRL7` | 14-bit DAC |
| `U48` + `U49` | LNA + BPF | RF receive path |

### 10.2 RF/ADC/DAC Clocks

- RF PLL: `LMX2594`
- ADC sample clock: `CLOCK_ADC` from SI5341
- ADC LVDS clock: `ADC_CLKOUTP/N`
- DAC clock: `DAF_CLK`
- External TCXO: 16.367667 MHz

### 10.3 Analog Rails

- `+3V3_ANA`
- `+5V_ANA`
- `REF_2V5`
- `ADC_VCM`
- `+1V8`
- `+1V25`

---

## 11. Sensors and GNSS

| Ref | Part | Function |
|---|---|---|
| `U50` | `TMP117DRVR` | High-accuracy digital temperature sensor, I2C |
| `U51` | `ICM-42688-P` | 6-axis IMU, I2C/SPI |
| `U52` | `MMC5983MA` | 3-axis magnetometer, I2C/SPI |
| `U54` | `BMP581` | Barometric pressure sensor, I2C/SPI |
| `U55` | `MAX-M10S-00B` | GNSS receiver module, UART/I2C |
| `U35`, `U53` | `TCA9548APWR` | 8-channel I2C multiplexers |
| `U36` | `TXB0108PW` | 8-bit bidirectional level translator |
| `U37` | `PCA9306` | I2C level translator |
| `U40` | `TXS0102DQE` | 2-bit level translator |

GNSS-related nets:

- `UART1_TX`
- `UART1_RX`
- `GNSS_PPS`
- `I2C_SCL1_0`
- `I2C_SDA1_0`

---

## 12. RTC and Security

| Ref | Part | Function |
|---|---|---|
| `U56` | `ATECC608B-MAHDA` | Secure element / crypto authentication, I2C |
| `U57` | `OPTIGA TPM SLB 9673 FW26` | TPM 2.0 security device, I2C/SPI |
| `BT1` | `Battery_Cell` | CR2032 coin-cell backup |
| `D10` | `RB521S30` | Schottky OR-ing for RTC backup |

Security bus:

- `I2C_SDA1_1` / `I2C_SCL1_1` for ATECC608B
- `I2C_SDA1_2` / `I2C_SCL1_2` for TPM

---

## 13. Energy Harvesting, BMC, and Telemetry

| Ref | Part | Function |
|---|---|---|
| `U58` | `BQ25570` | Nano-power boost charger + buck converter for energy harvesting |
| `C518` | `22 F, 5.5 V` | Supercapacitor storage |
| `U59` | `STM32G0B1RBT6` | BMC / telemetry MCU |
| `L13`, `L14` | 220 nH | Harvester boost/buck inductors |
| `J2` | 1×03 header | BMC header |
| `J4`, `J5` | 1×02 headers | BMC/debug headers |
| `J8` | 1×09 header | ePaper |
| `J11` | 1×04 header | Fan |



---

## 14. Expansion and Headers

| Ref | Type | Exported Function |
|---|---|---|
| `J7` | 1×10 | Expansion power/control header |
| `J14` | 1×10 | Expansion power/control header |
| `J15` | 1×10 | Expansion power/control header, I2C |
| `J16` | 1×10 | Expansion I2C/control header |
| `J10` | 2×07 | JTAG/debug |
| `J11` | 1×04 | Fan |
| `J6` | 1×02 | 3.3 V I2C |
| `J2` | 1×03 | BMC header |
| `J4`, `J5` | 1×02 | BMC/debug headers |
| `J8` | 1×09 | ePaper |
| `J13` | 1×22 FFC | MIPI CSI-2 camera |

Expansion headers carry rails such as:

- `+5V_SYS`
- `+3V3`
- `+15V_MAIN`
- `+5V_ANA`
- `+3V3_ANA`
- `+1V2_GTH`
- `+1V8_MGTRAVTT`
- `+1V8_VCCADC`
- `+0V9_GTR`
- `PS_POR_B`

---

## 15. Debug / Programming Interfaces

| Interface | Signals / Pins | Purpose |
|---|---|---|
| JTAG | `PS_JTAG_TCK`, `PS_JTAG_TDI`, `PS_JTAG_TDO`, `PS_JTAG_TMS`, `PS_SRST_B` | Zynq debug/programming |
| Boot mode | `PS_MODE0..3` | Boot source selection |
| QSPI boot | `QSPI_*` | QSPI NOR programming |
| SD boot | `SD0_*` | SD/eMMC boot |
| UART0 | `UART0_RX`, `UART0_TX` | Console/debug UART via CP2102N |
| UART1 | `UART1_RX`, `UART1_TX` | GNSS/BMC UART |
| USB-UART | CP2102N | Host PC serial console |
| BMC SWD | `J4`, `J5` | STM32G0B1 debug/programming |

---
