# BÁO CÁO BÀI TẬP KTLT - TUẦN 4

**Chủ đề:** Kadane + LIS O(n²) + Tư duy dãy con

- - -

## 0. HÀM TIỆN ÍCH CHUNG (UTILITIES)
*(Ghi chú các hàm dùng chung cho nhiều bài tập để tránh lặp lại phần thiết kế ở từng bài)*

- `trim(string s)`: Xóa khoảng trắng thừa ở 2 đầu chuỗi.
- `splitCSV(string line)`: Tách chuỗi theo dấu phẩy hoặc ký tự phân cách.
- *(Thêm các hàm khác nếu có...)*

- - -

## BÀI 1 – Max subarray sum (Kadane cơ bản) [Cơ bản

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
[Tuan4_Bai01.cpp](./Tuan4_Bai01.cpp)

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
max_sum=5
```

- - -

## BÀI 2 – Kadane có truy vết l, r [Cơ bản

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
[Tuan4_Bai02.cpp](./Tuan4_Bai02.cpp)

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
max_sum=5 / l=3 / r=5
```

- - -

## BÀI 3 – LIS độ dài O(n²) [Cơ bản

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
[Tuan4_Bai03.cpp](./Tuan4_Bai03.cpp)

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
lis_len=3
```

- - -

## BÀI 4 – Min subarray sum [Trung bình

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
[Tuan4_Bai04.cpp](./Tuan4_Bai04.cpp)

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
min_sum=-4 / l=0 / r=2
```

- - -

## BÀI 5 – LIS truy vết dãy con [Trung bình

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
[Tuan4_Bai05.cpp](./Tuan4_Bai05.cpp)

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
lis_len=3 / indices=0 1 3
```

- - -

## BÀI 6 – Đoạn có tổng lớn nhất độ dài đúng k [Cơ bản

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
[Tuan4_Bai06.cpp](./Tuan4_Bai06.cpp)

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
max_sum=5 / l=3 / r=5
```

- - -

## BÀI 7 – Kadane với nhiều bộ test [Trung bình

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
[Tuan4_Bai07.cpp](./Tuan4_Bai07.cpp)

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
6
-1
```

- - -

## BÀI 8 – Longest Non-Decreasing Subsequence [Trung bình

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
[Tuan4_Bai08.cpp](./Tuan4_Bai08.cpp)

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
lnds_len=3
```

- - -

## BÀI 9 – Maximum circular subarray [Nâng cao

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
[Tuan4_Bai09.cpp](./Tuan4_Bai09.cpp)

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
max_sum=5
```

- - -

## BÀI 10 – Đếm số dãy con tăng có độ dài = L [Nâng cao

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
[Tuan4_Bai10.cpp](./Tuan4_Bai10.cpp)

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
count=10
```

- - -

