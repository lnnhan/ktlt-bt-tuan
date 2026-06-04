# ĐỀ BÀI TẬP TUẦN 2

**QUY ĐỊNH CHUNG!**

- Mọi bài bắt buộc áp dụng M0: phân tích → thiết kế hàm → kiểm thử.
- Missing: ô trống hoặc NA/NaN (không phân biệt hoa/thường). KHÔNG dùng -1 làm missing.
- Số thực: dùng fixed + setprecision theo đề (mặc định 6 nếu không ghi).
- Bắt buộc kiểm tra lỗi mở file (cerr + return 1 khi fail).
- Chạy ít nhất 2 bộ test (1 thường + 1 case biên) trước khi nộp.
- Khuyến nghị: GCC/MinGW. \_\_int128 KHÔNG dùng được trên MSVC (Visual Studio).

---

Mảng 1D + Đa thức + Thống kê mô tả 

|**Bài 1. Tìm min, max, mean mảng [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|Đọc array.txt (n, rồi n số thực). Tính min, max, mean. Output: min=<f> / max=<f> / mean=<f> (setprecision(4)).|
|**Hướng dẫn:** |
|*Hàm cần viết: bool readArray(path, vector<double>&); double calcMean(vector<double>).*|
|*Case biên: n=0 → in 'EMPTY'; n=1 → min=max=mean=a[0].*|



|**Bài 2. Đếm phần tử thỏa điều kiện [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc mảng số nguyên. Đọc thêm ngưỡng k từ file config.txt.</p><p>Đếm và in: count\_ge\_k (số phần tử ≥ k) và count\_lt\_k (số phần tử < k).</p>|
|**Hướng dẫn:** |
|*Hàm cần viết: int countIf(vector<int>, int k, bool geq) hoặc 2 hàm riêng.*|
|*Case biên: n=0 → cả 2 đều 0; tất cả phần tử bằng k.*|



|**Bài 3. Tính đa thức tại nhiều điểm [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc poly.csv: 1 dòng chứa degree, a0, a1, ..., an.</p><p>Đọc x\_values.csv: nhiều giá trị x (mỗi dòng 1 giá trị).</p><p>Tính P(x) bằng Horner và ghi kết quả ra output.csv: x, P(x) (setprecision(6)).</p>|
|**Hướng dẫn:** |
|*Hàm cần viết: double evalHorner(vector<double> a, double x).*|
|*Case biên: degree=0 (hằng số); x\_values rỗng → output chỉ có header.*|
|*Horner: res = a[n]; for i=n-1..0: res = res\*x + a[i].*|



|**Bài 4. Variance và std deviation [Trung bình** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc mảng số thực. Tính variance quần thể (chia n) và std deviation. Output: mean=<f> / variance=<f> / std=<f> (setprecision(6)).</p><p>Xử lý: n=0 → 'EMPTY'; n=1 → variance=0, std=0.</p>|
|**Hướng dẫn:** |
|*Hàm cần viết: double calcVariance(vector<double>, double mean).*|
|*Dùng long double để tích lũy (xi - mean)^2, tránh catastrophic cancellation.*|
|*Case biên: tất cả phần tử bằng nhau → variance=0.*|



|**Bài 5. Đạo hàm đa thức [Trung bình** **]**   *Có hướng dẫn*||
| - | :- |
|<p>Đọc poly.csv (degree, a0..an). Tính hệ số đa thức đạo hàm P'(x).</p><p>Ghi derivative.csv: degree\_deriv, b0, b1, ..., b(n-1) theo đúng công thức b[i-1] = i \* a[i]. Sau đó tính P'(x) tại các x trong x\_values.csv và ghi kết quả.</p>||
|**Hướng dẫn:** ||
|*Đạo hàm: vector<double> deriv(n-1 phần tử): deriv[i] = (i+1)\*a[i+1], i từ 0 đến n-1.*||
|*Case biên: degree=0 → P'(x)=0 (đa thức hằng, đạo hàm là 0).*||
|*Hàm cần viết: vector<double> computeDerivCoeffs(vector<double> a).*||



|**Bài 6. Tìm vị trí phần tử lớn nhất [Cơ bản** **]**  |
| - |
|<p>Đọc mảng số nguyên. Tìm chỉ số của phần tử lớn nhất (nếu nhiều phần tử bằng nhau → lấy chỉ số nhỏ nhất).</p><p>Output: max\_val=<v> / max\_idx=<i>.</p>|



|**Bài 7. Chuẩn hoá mảng Min-Max [Cơ bản** **]**  |
| - |
|<p>Đọc mảng số thực (không có missing). Chuẩn hoá Min-Max: x' = (x - min) / (max - min). Ghi normalized.csv: i, original, scaled (setprecision(6)).</p><p>Xử lý: nếu max=min thì scaled=0 cho mọi phần tử.</p>|



|**Bài 8. Impute missing bằng median [Trung bình** **]**  |
| - |
|Đọc mảng có missing (NA/blank). Tính median của các giá trị hợp lệ. Thay missing bằng median. Ghi output.csv: i, value\_imputed. Ghi riêng summary: count\_valid, count\_missing, median. Median: sort các giá trị hợp lệ; nếu n lẻ → phần tử giữa; nếu n chẵn → trung bình 2 phần tử giữa.|



|**Bài 9. Histogram đơn giản [Trung bình** **]**  |
| - |
|<p>Đọc mảng số thực và số nguyên k (số bins). Chia đều khoảng [min, max] thành k bins. Đếm số phần tử trong mỗi bin. Ghi histogram.txt: mỗi dòng là [lo, hi): count.</p><p>Phần tử = max thì thuộc bin cuối.</p>|



|**Bài 10. Nội suy tuyến tính [Nâng cao** **]**  |
| - |
|<p>Đọc points.csv: các điểm (x\_i, y\_i) đã sắp xếp tăng theo x (không có x trùng). Đọc queries.csv: các điểm x cần nội suy.</p><p>Với mỗi x\_q: nếu nằm trong [x\_min, x\_max] → nội suy tuyến tính; ngoài khoảng → 'OUT\_OF\_RANGE'.</p><p>Ghi interpolated.csv: x\_q, y\_interp hoặc OUT\_OF\_RANGE.</p>|
