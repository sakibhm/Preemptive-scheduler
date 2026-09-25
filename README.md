# Preemptive-scheduler

A bare-metal, deterministic **Preemptive Scheduler** built completely from scratch in C and ARM Assembly for the **STM32F446RE** (ARM Cortex-M4) microcontroller. 

---

## 📊 Verification using Logic Analyzer

The scheduler is verified using a **Logic Analyzer**.

* **Task A (Fibonacci Sequence):** Controls GPIO Pin PA5.
* **Task B (Bubble Array Sort):** Controls GPIO Pin PA6.

![image alt](https://github.com/sakibhm/Preemptive-scheduler/blob/4ff770f4fb75e4af434bd4fb091a1da9c996296a/Screenshot%202026-09-25%20052534.png)
---

## 🛠️ Implementations

* **SVCall Exception:** Uses the `SVCall` supervisor exception handler to start the scheduler, load the very first task out of reset, and switch the CPU from Main Stack Pointer (MSP) to Process Stack Pointer (PSP).

* **SysTickException:**  Sets up the internal `SysTick` timer to fire a hardware interrupt every 1ms. The handler triggers a context switch, pausing the current task and jumping to the next task.

---

### Learnings

This project provided hands-on experience with:

- MSP and PSP
- Exception entry/return
- `EXC_RETURN`
- Hardware and software stack frames
- ARM calling conventions
- Register-level programming
- C ↔ ARM Assembly interaction
- Preemptive scheduling
- Task context preservation

---

## 📂 Project Structure

```text
Preemptive-scheduler/
├── Inc/
│   ├── Drivers/
│   │   ├── SysTick.h
│   │   └── usart2.h
│   ├── scheduler.h
│   ├── start_first_task.h
│   ├── stm32f446.h
│   ├── task_init.h
│   ├── taskA.h
│   ├── taskB.h
│   └── TCB.h
├── Src/
│   ├── Drivers/
│   │   ├── SysTick.c
│   │   └── usart2.c
│   ├── main.c
│   ├── scheduler.c
│   ├── task_init.c
│   ├── taskA.c
│   └── taskB.c
├── .gitignore
├── linker_stm32f446.ld
├── Makefile
├── README.md
├── start_first_task.s
├── startup_stm32f446.s
├── svc_handler.s
└── systick_handler.s
```

---

## ⚙️ Compilation & Flashing

### Build Project
```bash
make
```

### Clean Build Artifacts
```bash
make clean
```
### Flashing
```bash
make flash
```
