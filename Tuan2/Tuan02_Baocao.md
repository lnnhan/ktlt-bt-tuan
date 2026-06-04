# BÁO CÁO BÀI TẬP KTLT - TUẦN 2

**Chủ đề:** Mảng 1D + Đa thức + Thống kê mô tả

- - -

## 0. HÀM TIỆN ÍCH CHUNG (UTILITIES)
*(Ghi chú các hàm dùng chung cho nhiều bài tập để tránh lặp lại phần thiết kế ở từng bài)*

- `trim(string s)`: Xóa khoảng trắng thừa ở 2 đầu chuỗi.
- `splitCSV(string line)`: Tách chuỗi theo dấu phẩy hoặc ký tự phân cách.
- *(Thêm các hàm khác nếu có...)*

- - -

## BÀI 1 – Tìm min, max, mean mảng [Cơ bản

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
[Tuan2_Bai01.cpp](./Tuan2_Bai01.cpp)

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
min=1.2000 / max=7.8000 / mean=4.0200
```

- - -

## BÀI 2 – Đếm phần tử thỏa điều kiện [Cơ bản

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
[Tuan2_Bai02.cpp](./Tuan2_Bai02.cpp)

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
count_ge_k=4
count_lt_k=3
```

- - -

## BÀI 3 – Tính đa thức tại nhiều điểm [Cơ bản

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
[Tuan2_Bai03.cpp](./Tuan2_Bai03.cpp)

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
Done. Results written to output.csv
```

- - -

## BÀI 4 – Variance và std deviation [Trung bình

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
[Tuan2_Bai04.cpp](./Tuan2_Bai04.cpp)

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
mean=4.000000 / variance=1.000000 / std=1.000000
```

- - -

## BÀI 5 – Đạo hàm đa thức [Trung bình

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
[Tuan2_Bai05.cpp](./Tuan2_Bai05.cpp)

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
Done. Derivative written to derivative.csv and deriv_output.csv
```

- - -

## BÀI 6 – Tìm vị trí phần tử lớn nhất [Cơ bản

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
[Tuan2_Bai06.cpp](./Tuan2_Bai06.cpp)

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
max_val=9 / max_idx=1
```

- - -

## BÀI 7 – Chuẩn hoá mảng Min-Max [Cơ bản

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
[Tuan2_Bai07.cpp](./Tuan2_Bai07.cpp)

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
Done. Results written to normalized.csv
```

- - -

## BÀI 8 – Impute missing bằng median [Trung bình

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
[Tuan2_Bai08.cpp](./Tuan2_Bai08.cpp)

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
Done. Imputed data in output.csv, summary in summary.txt
```

- - -

## BÀI 9 – Histogram đơn giản [Trung bình

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
[Tuan2_Bai09.cpp](./Tuan2_Bai09.cpp)

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
Done. Written to histogram.txt
```

- - -

## BÀI 10 – Nội suy tuyến tính [Nâng cao

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
[Tuan2_Bai10.cpp](./Tuan2_Bai10.cpp)

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
Done. Results written to interpolated.csv
```

- - -

