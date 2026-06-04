# BÁO CÁO BÀI TẬP KTLT - TUẦN 6

**Chủ đề:** Ma trận 2D + Prefix Sum 2D

- - -

## 0. HÀM TIỆN ÍCH CHUNG (UTILITIES)
*(Ghi chú các hàm dùng chung cho nhiều bài tập để tránh lặp lại phần thiết kế ở từng bài)*

- `trim(string s)`: Xóa khoảng trắng thừa ở 2 đầu chuỗi.
- `splitCSV(string line)`: Tách chuỗi theo dấu phẩy hoặc ký tự phân cách.
- *(Thêm các hàm khác nếu có...)*

- - -

## BÀI 1 – Tổng hàng và cột ma trận [Cơ bản

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
[Tuan6_Bai01.cpp](./Tuan6_Bai01.cpp)

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
Done. Written to row_sums.txt and col_sums.txt
```

- - -

## BÀI 2 – Kiểm tra ma trận đối xứng [Cơ bản

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
[Tuan6_Bai02.cpp](./Tuan6_Bai02.cpp)

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
is_symmetric=0
```

- - -

## BÀI 3 – Xây dựng prefix sum 2D [Cơ bản

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
[Tuan6_Bai03.cpp](./Tuan6_Bai03.cpp)

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
Done. Written to pre2d.txt
```

- - -

## BÀI 4 – Trả lời truy vấn tổng vùng [Trung bình

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
[Tuan6_Bai04.cpp](./Tuan6_Bai04.cpp)

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
12
```

- - -

## BÀI 5 – Ma trận đường chéo [Trung bình

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
[Tuan6_Bai05.cpp](./Tuan6_Bai05.cpp)

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
main_diag_sum=15 / anti_diag_sum=15 / is_diagonal=0
```

- - -

## BÀI 6 – Nhân hai ma trận [Trung bình

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
[Tuan6_Bai06.cpp](./Tuan6_Bai06.cpp)

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
Done. Result written to output.txt
```

- - -

## BÀI 7 – Vùng con tổng lớn nhất (brute force) [Trung bình

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
[Tuan6_Bai07.cpp](./Tuan6_Bai07.cpp)

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
max_sum=45 / x1=0 / y1=0 / x2=2 / y2=2
```

- - -

## BÀI 8 – Kiểm tra ma trận tam giác [Trung bình

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
[Tuan6_Bai08.cpp](./Tuan6_Bai08.cpp)

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
is_upper=0 / is_lower=0
```

- - -

## BÀI 9 – Xoay ma trận 90° theo chiều kim đồng hồ [Trung bình

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
[Tuan6_Bai09.cpp](./Tuan6_Bai09.cpp)

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
Done. Rotated matrix written to rotated.txt
```

- - -

## BÀI 10 – Đếm vùng con tổng bằng K [Nâng cao

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
[Tuan6_Bai10.cpp](./Tuan6_Bai10.cpp)

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
count=0
```

- - -

