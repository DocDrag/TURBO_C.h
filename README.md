## 📖 Table of Contents
- [English](#english)
  - [⚠ Important Notes](#⚠-important-notes)
  - [📥 Installation Guide](#📥-installation-guide)
  - [🔧 Supported Functions](#🔧-supported-functions)
  - [📜 License](#📜-license)
- [ภาษาไทย](#ภาษาไทย)
  - [⚠ หมายเหตุสำคัญ](#⚠-หมายเหตุสำคัญ)
  - [📥 วิธีติดตั้ง](#📥-วิธีติดตั้ง)
  - [🔧 ฟังก์ชันที่รองรับ](#🔧-ฟังก์ชันที่รองรับ)

---

## 🇬🇧 **English**  

### ⚠ Important Notes
- Some functions may **not be fully compatible** with the original Turbo C++ environment.
- This library **relies on Windows API** for console manipulation and ANSI escape codes.
- You **must run Dev C++ and Code::Blocks as Administrator** to display extended ASCII characters correctly.
- This library is **not** part of the mingw-w64 runtime package.

---

### 📥 Installation Guide (Dev C++)  
⚠ **This is only a recommendation** to make usage more convenient.  
You may place `TURBO_C.h` anywhere you prefer based on your project needs.  

To use this library with **Dev C++**, follow these steps:

#### **1️⃣ Copy the file to the correct directory**  
Move `TURBO_C.h` to the **Include** folder in Dev C++ for easy access:  
```bash
C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include
```

#### **2️⃣ Open Dev C++ and use `#include`**
Once installed, you can include and use the library normally:
```c
#include <stdio.h>
#include <TURBO_C.h>

int main() {
    clrscr();
    textcolor(10);
    printf("Hello, Turbo C++!\n");
    return 0;
}
```

---

### 🔧 Supported Functions
This library provides Turbo C++-style console functions:
```c
clrscr();         // Clears the console screen
randomize();      // Initializes random number generator
gotoxy(x, y);     // Moves the cursor to (x, y) position
textcolor(c);     // Sets the text color
textbackground(c);// Sets the background color
setcolor(fg, bg);// Sets both text and background color
delay(ms);        // Delays execution in milliseconds
```

---

## 🇹🇭 **ภาษาไทย**  

### ⚠ หมายเหตุสำคัญ
- ฟังก์ชันบางอย่าง **อาจไม่สามารถใช้งานได้ 100%** เหมือน Turbo C++ ดั้งเดิม  
- ไลบรารีนี้ใช้ **Windows API และ ANSI Escape Code** สำหรับจัดการคอนโซล  
- **จำเป็นต้องรัน Dev C++ และ Code::Blocks ในโหมด Administrator** มิฉะนั้นอาจแสดงผลตัวอักษร ASCII พิเศษผิดพลาด  
- ไลบรารีนี้ **ไม่ใช่** ส่วนหนึ่งของ mingw-w64 runtime package  

---

### 📥 วิธีติดตั้ง (Dev C++)  
⚠ **นี่เป็นเพียงคำแนะนำ** เพื่อช่วยให้การใช้งานสะดวกขึ้นเท่านั้น  
ผู้ใช้สามารถเลือกตำแหน่งไฟล์ `TURBO_C.h` ตามความต้องการของโปรเจกต์ได้  

หากต้องการใช้ไลบรารีนี้กับ **Dev C++**, สามารถทำตามคำแนะนำนี้:

#### **1️⃣ คัดลอกไฟล์ไปยังโฟลเดอร์ Include**  
นำไฟล์ `TURBO_C.h` ไปไว้ที่โฟลเดอร์ **Include** ของ Dev C++ เพื่อให้ใช้งานได้ง่ายขึ้น:  
```bash
C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include
```

#### **2️⃣ เปิด Dev C++ และใช้งาน `#include`**
เมื่อติดตั้งแล้ว สามารถเรียกใช้ไลบรารีได้ตามปกติ:
```c
#include <stdio.h>
#include <TURBO_C.h>

int main() {
    clrscr();
    textcolor(10);
    printf("Hello, Turbo C++!\n");
    return 0;
}
```

---

### 🔧 ฟังก์ชันที่รองรับ
ไลบรารีนี้รองรับฟังก์ชันที่คุ้นเคยจาก Turbo C++:
```c
clrscr();         // ล้างหน้าจอคอนโซล
randomize();      // เริ่มต้นตัวสร้างเลขสุ่ม
gotoxy(x, y);     // ย้ายตำแหน่งเคอร์เซอร์ไปที่ (x, y)
textcolor(c);     // กำหนดสีตัวอักษร
textbackground(c);// กำหนดสีพื้นหลัง
setcolor(fg, bg);// กำหนดทั้งสีตัวอักษรและพื้นหลัง
delay(ms);        // หน่วงเวลาตามจำนวนมิลลิวินาที
```

---

## 📜 License | ใบอนุญาตใช้งาน

This library is provided **as-is**, without warranty of any kind.  
For more information, visit:  
🔗 **[GitHub Repository](https://github.com/DocDrag/TURBO_C.h)**  

---

### 🇹🇭 **คำอธิบายภาษาไทย**  
ไลบรารีนี้ถูกแจกจ่าย **"ตามสภาพ"** (**As-Is**) โดยไม่มีการรับประกันใด ๆ ทั้งสิ้น  
- **ผู้พัฒนาไม่มีภาระผูกพัน** ในการแก้ไขข้อผิดพลาดหรือให้การสนับสนุน  
- การใช้งานไลบรารีนี้เป็นความรับผิดชอบของผู้ใช้  
- หากเกิดข้อผิดพลาด, ปัญหาทางเทคนิค หรือความเสียหายใด ๆ **ผู้พัฒนาไม่มีส่วนรับผิดชอบ**  

หากต้องการข้อมูลเพิ่มเติม, โปรดดูที่:  
🔗 **[GitHub Repository](https://github.com/DocDrag/TURBO_C.h)**

---
