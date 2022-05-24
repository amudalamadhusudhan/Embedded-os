# Embedded OS Assignment

## Day 1

- 2 Tier and 3 Tier Embedded Systems
- Hardware
  - CPU
    - PC/ IP
    - GPRs
    - Flags
    - Stack Pointer (SP)
  - Memory
    - Code
    - Data
  - Peripheral
- Bare Metal Systems
- SP, SF, Stack
  - SP - Register inside a CPU -> pointing to the top of stack
  - Stack - Chunk of memory
  - SF - Frame created on the Stack when you call a function. Deleted when you return from the function
- Frame Pointer - points to the base of the frame
- How are arguments passed to the function
  - Stack
  - Registers

## Day 2

- Booting procedure

  - ROM BL
  - PBL
  - SBL (Uboot)
  - Kernel (Linux)
  - RFS (Buildroot)
