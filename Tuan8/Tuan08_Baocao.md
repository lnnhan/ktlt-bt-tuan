# BÁO CÁO BÀI TẬP KTLT - TUẦN 8

**Chủ đề:** File + Struct: Đa thức Record + Ma trận Phân số

- - -

## 0. HÀM TIỆN ÍCH CHUNG (UTILITIES)
*(Ghi chú các hàm dùng chung cho nhiều bài tập để tránh lặp lại phần thiết kế ở từng bài)*

- `trim(string s)`: Xóa khoảng trắng thừa ở 2 đầu chuỗi.
- `splitCSV(string line)`: Tách chuỗi theo dấu phẩy hoặc ký tự phân cách.
- *(Thêm các hàm khác nếu có...)*

- - -

## BÀI 1 – Đọc danh sách đa thức từ CSV [Cơ bản

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai01.cpp](./Tuan8_Bai01.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Summary written to summary.txt
```

- - -

## BÀI 2 – Tính P(x) và ghi report [Cơ bản

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai02.cpp](./Tuan8_Bai02.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Results written to report.csv
```

- - -

## BÀI 3 – Thống kê hệ số đa thức [Cơ bản

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai03.cpp](./Tuan8_Bai03.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Stats written to stats.csv
```

- - -

## BÀI 4 – Cộng hai đa thức [Trung bình

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai04.cpp](./Tuan8_Bai04.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Sums written to sum.csv
```

- - -

## BÀI 5 – Ma trận phân số: cộng và nhân [Trung bình

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai05.cpp](./Tuan8_Bai05.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Results written to result.csv
```

- - -

## BÀI 6 – Đạo hàm và đánh giá đa thức [Cơ bản

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai06.cpp](./Tuan8_Bai06.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Written to deriv_report.csv
```

- - -

## BÀI 7 – Tìm nghiệm nguyên của đa thức [Trung bình

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai07.cpp](./Tuan8_Bai07.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Roots written to roots.csv
```

- - -

## BÀI 8 – Ma trận đơn vị phân số [Trung bình

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai08.cpp](./Tuan8_Bai08.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
is_identity_product=1
```

- - -

## BÀI 9 – Đa thức Lagrange nội suy [Nâng cao

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai09.cpp](./Tuan8_Bai09.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Written to lagrange_out.csv
```

- - -

## BÀI 10 – Phân tích bình phương tổng [Nâng cao

### 1. Phân tích & Ràng buộc
- **Yêu cầu:** [Mô tả mục tiêu của bài toán]
- **Input / Output:** [Mô tả định dạng file hoặc dữ liệu đầu vào/đầu ra]
- **Case biên (Edge cases):** [Các trường hợp rủi ro]

### 2. Thiết kế & Độ phức tạp
- **Cấu trúc dữ liệu:** [CTDL sử dụng]
- **Thuật toán chính:** [Luồng xử lý]
- **Đánh giá độ phức tạp:**
  - Time (Thời gian): $O(N)$
  - Space (Không gian bộ nhớ): $O(1)$

### 3. Code
[Tuan8_Bai10.cpp](./Tuan8_Bai10.cpp)

### 4. Test Cases
| Loại Test | Input (Hoặc Tên File Test) | Output mong đợi | Kết quả |
| :--- | :--- | :--- | :--- |
| **Chuẩn** | `input_normal.txt` | Đọc và xử lý đúng yêu cầu | Pass |
| **Ngoại lệ** | `input_empty.txt` | Cảnh báo lỗi, không crash | Pass |

### 5. Kết quả & Kinh nghiệm
- **Kết quả thực thi:** Chương trình chạy ổn định, đúng output, không bị Memory Leak.
- **Khó khăn / Bài học rút ra:** [Ghi lại bug đáng nhớ hoặc logic mất nhiều thời gian để xử lý]

### 6. Output thực tế
```text
Done. Written to stats.csv
```

- - -

