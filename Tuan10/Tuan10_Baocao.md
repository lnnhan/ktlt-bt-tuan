# BÁO CÁO BÀI TẬP KTLT - TUẦN 10

**Chủ đề:** Tổng hợp M0: Mini-project + Module hoá

- - -

## 0. HÀM TIỆN ÍCH CHUNG (UTILITIES)
*(Ghi chú các hàm dùng chung cho nhiều bài tập để tránh lặp lại phần thiết kế ở từng bài)*

- `trim(string s)`: Xóa khoảng trắng thừa ở 2 đầu chuỗi.
- `splitCSV(string line)`: Tách chuỗi theo dấu phẩy hoặc ký tự phân cách.
- *(Thêm các hàm khác nếu có...)*

- - -

## BÀI 1 – Pipeline M0 hoàn chỉnh: CSV Cleaning [Cơ bản

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
[Tuan10_Bai01.cpp](./Tuan10_Bai01.cpp)

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
Done. report.csv and summary.txt written.
```

- - -

## BÀI 2 – Fraction List tổng hợp [Cơ bản

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
[Tuan10_Bai02.cpp](./Tuan10_Bai02.cpp)

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
Done. Written to fraction_out.csv
```

- - -

## BÀI 3 – Polynomial records + evaluate [Cơ bản

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
[Tuan10_Bai03.cpp](./Tuan10_Bai03.cpp)

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
Done. Written to report.csv
```

- - -

## BÀI 4 – Multi-query prefix sum tổng hợp [Trung bình

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
[Tuan10_Bai04.cpp](./Tuan10_Bai04.cpp)

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
Done. Answers written to answers.txt
```

- - -

## BÀI 5 – Text analysis pipeline [Trung bình

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
[Tuan10_Bai05.cpp](./Tuan10_Bai05.cpp)

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
Done. freq.csv and summary.txt written.
```

- - -

## BÀI 6 – Dashboard tổng hợp 1 file [Trung bình

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
[Tuan10_Bai06.cpp](./Tuan10_Bai06.cpp)

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
Done. Written to dashboard.csv
```

- - -

## BÀI 7 – Sliding window multi-stat [Trung bình

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
[Tuan10_Bai07.cpp](./Tuan10_Bai07.cpp)

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
Done. Written to multi_rolling.csv
```

- - -

## BÀI 8 – Sort + search tổng hợp [Trung bình

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
[Tuan10_Bai08.cpp](./Tuan10_Bai08.cpp)

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
NOT_FOUND
NOT_FOUND
```

- - -

## BÀI 9 – Phát hiện outlier IQR [Nâng cao

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
[Tuan10_Bai09.cpp](./Tuan10_Bai09.cpp)

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
Done. outliers.csv and summary.txt written.
```

- - -

## BÀI 10 – Mini-project tự do: chọn 1 [Nâng cao

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
[Tuan10_Bai10.cpp](./Tuan10_Bai10.cpp)

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
Done. cleaned.csv, normalized.csv, histogram.txt, summary.txt written.
```

- - -

