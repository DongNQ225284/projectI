# Morse Shell

Morse Shell là một **command-line tool** được viết bằng **C++**, hỗ trợ **chuyển đổi giữa văn bản (text) và mã Morse (Morse code)** từ file, cùng với các lệnh quản lý cơ bản như `exit` và `clear`.

---

## Tính năng chính

- Chuyển đổi từ **text → Morse code** và **Morse code → text**.
- Xử lý file input/output.
- Kiểm tra định dạng file Morse code hợp lệ.
- Báo lỗi và cảnh báo nếu có ký tự không hỗ trợ.
- Hỗ trợ các lệnh shell cơ bản:
  - `exit` – Thoát chương trình.
  - `clear` – Xóa màn hình console.
  - `morse <input_file> <output_file>` – Thực hiện chuyển đổi Morse ↔ Text.

---

## Yêu cầu hệ thống

- **Hệ điều hành:** Windows / Linux / macOS
- **Compiler:** G++ / Visual Studio / Clang
- **C++ Standard:** C++11 trở lên

---

## Cài đặt

1. Clone repository:

```bash
git clone <repository-url>
cd <repository-folder>
```

2. Biên dịch chương trình

```bash
g++ main.cpp -o morseShell
```

## Cách sử dụng

```bash
morseShell.exe
```

Shell sẽ hiển thị dấu nhắc `>`

```
> morse input.txt output.txt
```

Nếu file input là text, chương trình sẽ chuyển sang Morse code.

Nếu file input là Morse code hợp lệ, chương trình sẽ chuyển sang text.

Nếu file output đã tồn tại, chương trình sẽ hỏi xác nhận ghi đè.

Các lệnh cơ bản khác:

```bash
> clear  # Xóa màn hình
> exit   # Thoát chương trình
```

## Quy tắc Morse code

Mỗi ký tự cách nhau bằng dấu space `( )`.

Ký tự space trong văn bản được chuyển thành `/` trong Morse.

Ký tự không hỗ trợ được thay bằng `........` và in cảnh báo ra console.

**Ví dụ**

Input (text): `hello world`
Output (Morse code): `.... . .-.. .-.. --- / .-- --- .-. .-.. -..`

Input (Morse code): `.... . .-.. .-.. --- / .-- --- .-. .-.. -..`
Output (text): `hello world`

## Ghi chú

Chỉ xử lý ký tự: `a-z`, `0-9`, `. , : ? -` và space.

Morse code phải gồm các ký tự `.`, `-`, `/`. Các ký tự khác trong file Morse sẽ báo lỗi.

File input/output phải tồn tại trong cùng thư mục hoặc cung cấp đường dẫn đầy đủ.
