**TUẦN 1** 

**File I/O + String cơ bản + Pipeline M0**

Mỗi bài trình bày theo M0: Phân tích bài toán → Thiết kế hàm → Code → Test → Kết quả  

**BÀI 1 – ĐỌC VÀ ĐẾM DÒNG FILE**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đọc text.txt nhiều dòng, đếm dòng rỗng và không rỗng, ghi output.txt. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- File rỗng; dòng chỉ chứa khoảng trắng. 
2. **THIẾT KẾ HÀM** 
- readLines(path, lines); writeOutput(path, nonEmpty, empty) 
3. **CODE** 

Xem file: Tuan1\_Bai01.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- 2 dòng không rỗng; 0 dòng rỗng. 

**BÀI 2 – TÁCH TRƯỜNG CSV 1 HÀNG**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đọc 1 dòng CSV, tách theo dấu phẩy, trim từng ô và in số trường. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Dòng rỗng; dòng chỉ có dấu phẩy. 
2. **THIẾT KẾ HÀM** 
- splitCSV(line); trim(s) 
3. **CODE** 

Xem file: Tuan1\_Bai02.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- Đã xử lý 7 dòng (bao gồm header). Mỗi dòng có 3 trường. 
- Phát hiện giá trị thiếu/N/A ở một số ô (dòng 4 cột 1 trống; dòng 6 cột 2='NaN'; dòng 7 có 'N/A'). 

**BÀI 3 – PHÁT HIỆN MISSING TOKEN**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đọc data.csv 1 cột, in chỉ số dòng có token missing. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Token khoảng trắng; token 0 không missing. 
2. **THIẾT KẾ HÀM** 
- isMissingToken(t); trim; lowerStr 
3. **CODE** 

Xem file: Tuan1\_Bai03.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- 11 dòng dữ liệu; phát hiện nhiều giá trị thiếu/không hợp lệ (na, N/A, NaN, blank). 

**BÀI 4 – THỐNG KÊ CỘT SỐ TỪ CSV**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Bỏ missing, tính count, missing, min, max, mean, ghi output.txt. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Toàn missing; chỉ có 1 giá trị. 
2. **THIẾT KẾ HÀM** 
- readCSV1Col(); computeStats() 
3. **CODE** 

Xem file: Tuan1\_Bai04.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- 7 giá trị hợp lệ; 3 giá trị thiếu. 
- Khoảng giá trị: min=10.00; max=30.00; trung bình=18.57.** 

**BÀI 5 – GHI REPORT CSV NHIỀU CỘT**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đọc điểm 3 môn, missing coi là 0, tính total và rank. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Tất cả điểm missing; id rỗng. 
2. **THIẾT KẾ HÀM** 
- parse row bằng splitCSV; rankOf(total) 
3. **CODE** 

Xem file: Tuan1\_Bai05.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- Tổng 10 học sinh; phân loại tổng hợp: Gioi=4; Kha=2; Trung binh=4; Yeu=0. 
- Một số giá trị điểm nguồn có missing/N/A cần làm sạch trước khi tính. 

**BÀI 6 – ĐẾM TỪ TRONG FILE TEXT**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đếm tổng từ và số từ duy nhất, split theo khoảng trắng. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- File rỗng; từ trùng lặp. 
2. **THIẾT KẾ HÀM** 
- ifstream >> word; set<string> 
3. **CODE** 

Xem file: Tuan1\_Bai06.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- Kết quả (stdout): total\_words=6 / unique\_words=5 

**BÀI 7 – KIỂM TRA FILE CÓ HEADER**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Dòng đầu là header nếu mọi cell không parse được thành số. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- File rỗng; header lẫn số. 
2. **THIẾT KẾ HÀM** 
- splitCSV(); isNumber(cell) 
3. **CODE** 

Xem file: Tuan1\_Bai07.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

has\_header=1 

columns=TUAN5 

**BÀI 8 – LỌC DÒNG THEO ĐIỀU KIỆN**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đọc lo-hi từ config, giữ dòng có value hợp lệ trong khoảng. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Value missing; ngoài khoảng. 
2. **THIẾT KẾ HÀM** 
- read config; filter rows 
3. **CODE** 

Xem file: Tuan1\_Bai08.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- Danh sách giữ: Alice, Diana, Eve, Frank (kept=4). 
- Thông báo: kept=4 / dropped=4. 

**BÀI 9 – MERGE 2 FILE CSV THEO ID**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Inner join fileA và fileB theo id, ghi diff. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Id chỉ xuất hiện một file. 
2. **THIẾT KẾ HÀM** 
- map id->score; duyệt giao khóa 
3. **CODE** 

Xem file: Tuan1\_Bai09.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- 2 bản ghi hợp nhất: A2 (score\_A=76, score\_B=73, diff=3), A4 (91,88,3). 
- Khoảng điểm: score\_A 76-91; score\_B 73-88.** 

**BÀI 10 – PHÂN TÍCH LOG FILE**

1. **PHÂN TÍCH BÀI TOÁN** 

**Input/Output** 

- Đếm INFO/WARN/ERROR, tìm ERROR đầu và cuối. 

**Ràng buộc** 

- Kiểm tra lỗi mở file khi đọc/ghi; tách xử lý thành hàm; dùng định dạng output đúng đề. 

**Case biên** 

- Không có ERROR; dòng sai format. 
2. **THIẾT KẾ HÀM** 
- parse [LEVEL]; substr timestamp 
3. **CODE** 

Xem file: Tuan1\_Bai10.cpp 

4. **TEST** 

Test 1: dữ liệu thường theo đề → chương trình ghi/in đúng định dạng yêu cầu. 

Test 2: case biên nêu ở phần phân tích → chương trình không crash và in kết quả hợp lệ. 

5. **KẾT QUẢ** 

Tóm tắt kết quả: 

- INFO=3; WARN=1; ERROR=2. 
- Lỗi đầu tiên: 2026-05-29 08:10:23; lỗi cuối: 2026-05-29 08:20:45. 
