# Journal : Fusion Board

*Author : Hemanth*
*YSWS : Pixl*
*Goal : Make a beacon worthy project and put up at least 100 hours*

---

## Notes :

Please read this Journal for clear day to day insights + not so funny jokes + AI Usage.

---

## Session 1 : 

[Lapse](https://lapse.hackclub.com/timelapse/AL27EAvf0Gup)

**Time : 6 hr 15 min**

I decided to make a custom Dev Board which is *Unique*, *Hard to make* and most importantly *built from scratch* with least amount of **AI usage**. 

Today I completed setup of my project, setup included Pixl Project, Github Repo, File structure and KiCad setup. 

I planned the design and layout, basically all my other projects till this point involved Sections in a sheet, but thats not enough for a Dev Board this scale. so it requires multiple hierarchical sheets with separate sections.

Today I completed Section 1 which is related to Power. It simply receives power and safely passes it to other section.

**AI USAGE** : 5-15 minutes, when we search in google we get AI insights so I just read them, and used Deepseek for connections in only two instants where I didnt understand connections of MUX so I used Deepseek

![Schematic](PCB\Devboard\images\Schematic\01_Power\S01_Full.png)

---

## Session 2 :

[Lapse](https://lapse.hackclub.com/timelapse/RgZXFPeaefZ3)

**Time : 2 hr 30 min**

Today I completed Section 1 and worked on Section 2. Section 2 is about battery charging + power gauge. 

**AI USAGE** : 2 minutes, once I used to check pin names of a shunt resistor and ideal connection (Search insights). And once to verify sanity.

![Schematic](PCB\Devboard\images\Schematic\02_Battery\S2.png)

---

## Session 3 : 

[Lapse](https://lapse.hackclub.com/timelapse/42OSYWENe3S8)

**Time : 4 hrs 18 min**

Today I completed Section 3 which is responsible to step-down main power line into different voltages like +5V, +3.3V, +0.8V, +1.5V.
And this time I actually read datasheets !!

![Schematic](PCB\Devboard\images\Schematic\03_Power_Tree\S3_F.png)

And I created new repo !!

**AI USAGE** : None.

---

## Session 4 :

**Time : 11 hrs 52 min**


[Lapse](https://lapse.hackclub.com/timelapse/BUebwhysWVGx)

Fixed a few mistakes in previous section, chose 900 pin Zynq (regretting my life choices), and discovered KiPart a python package to create Symbol, and created footprint manually.

**AI USAGE**: None.

---

## Session 5 :

[Lapse](https://lapse.hackclub.com/timelapse/Iurz7R1SKVbi)

**Time : 7 hr 32 min**

Began on DDR4 memory and realized that I followed wrong datasheet, and had to scrap it and begin over.


**AI USAGE** : Two small instances (less than 2 minutes) for understanding chinese parts of my datasheet.

---

##  Session 6 :

[Lapse](https://lapse.hackclub.com/timelapse/Otw7jyXCwGHQ)

**Time : 2 hr 42 min**

Fixed mistakes and began on Zynq, completed power rails + capacitors.

**AI USAGE** : None.

---

## Decision 

I decided to not use AI at all (very strict). Not even for understanding something. (Google search insights excluded).

---

## Session 7 : 

[Lapse](https://lapse.hackclub.com/timelapse/XaJOH0bwTB7O)

**Time : 1 hr 19 min**

Before I begin Zynq again I corrected few mistakes, and checked from beginning. Read Zynq User guide once again.

- [x] Section 1
- [x] Section 2
- [x] Section 3
- [x] Check 1
- [x] Check 2
- [ ] Power Section, adding missing nets.
- [ ] Zynq
- [ ] DDR4 Memory


**AI USAGE** : None.

---

## Summary of WEEK 1


| Session | Time | Work completed / summary | Lapse link | AI usage (0–5) | AI usage notes |
|---|---:|---|---|---:|---|
| 1 | 6 hr 15 min | Project setup: Pixl project, GitHub repo, file structure, KiCad setup; planned hierarchical sheets; completed Power Section 1. | [Lapse](https://lapse.hackclub.com/timelapse/AL27EAvf0Gup) | **3** | 5–15 min total: Google AI insights; DeepSeek used twice for MUX connections. |
| 2 | 2 hr 30 min | Completed Section 1; worked on Section 2: battery charging + power gauge. | [Lapse](https://lapse.hackclub.com/timelapse/RgZXFPeaefZ3) | **1** | ~2 min: shunt resistor pin names/ideal connection; sanity check via search insights. |
| 3 | 4 hr 18 min | Completed Section 3: power tree stepping down to +5V, +3.3V, +0.8V, +1.5V; read datasheets; created new repo. | [Lapse](https://lapse.hackclub.com/timelapse/42OSYWENe3S8) | **0** | None. |
| 4 | 11 hr 52 min | Fixed previous-section mistakes; chose 900-pin Zynq; used KiPart to create symbol; created footprint manually. | [Lapse](https://lapse.hackclub.com/timelapse/BUebwhysWVGx) | **0** | None. |
| 5 | 7 hr 32 min | Began DDR4 memory; found wrong datasheet and scrapped/restarted. | [Lapse](https://lapse.hackclub.com/timelapse/Iurz7R1SKVbi) | **1** | <2 min total: two small instances for understanding Chinese parts of datasheet. |
| 6 | 2 hr 42 min | Fixed mistakes; began Zynq; completed power rails + capacitors. | [Lapse](https://lapse.hackclub.com/timelapse/Otw7jyXCwGHQ) | **0** | None. |
| 7 | 1 hr 19 min | Corrected mistakes; rechecked from beginning; reread Zynq User Guide; updated checklist: S1–S3 + Check 1/2 done; power missing nets, Zynq, DDR4 pending. | [Lapse](https://lapse.hackclub.com/timelapse/XaJOH0bwTB7O) | **0** | None. |
| 8 | ~ 4 hr | Journal, etc | - | 0 | None. |
| **Total** | **40 hr 12 min** |  |  |  |  |

**AI usage score:** `0 = none`, `5 = Highest in this log.` (Session 1); brief or minor lookups scored as `1`. Google search AI insights are counted only where the log explicitly mentions them.

**Decision after Session 6:** strict no-AI policy — not even for understanding something; Google search insights excluded.
