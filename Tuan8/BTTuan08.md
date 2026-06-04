# ĐỀ BÀI TẬP TUẦN 8

**QUY ĐỊNH CHUNG!**

- Mọi bài bắt buộc áp dụng M0: phân tích → thiết kế hàm → kiểm thử.
- Missing: ô trống hoặc NA/NaN (không phân biệt hoa/thường). KHÔNG dùng -1 làm missing.
- Số thực: dùng fixed + setprecision theo đề (mặc định 6 nếu không ghi).
- Bắt buộc kiểm tra lỗi mở file (cerr + return 1 khi fail).
- Chạy ít nhất 2 bộ test (1 thường + 1 case biên) trước khi nộp.
- Khuyến nghị: GCC/MinGW. \_\_int128 KHÔNG dùng được trên MSVC (Visual Studio).

---

File + Struct: Đa thức Record + Ma trận Phân số 

5 bài Cơ bản/Trung bình (có hướng dẫn)   •   5 bài Không hướng dẫn



|**Bài 1. Đọc danh sách đa thức từ CSV [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|Đọc polynomials.csv (id,degree,a0..an). Thiếu hệ số → 0. degree<0 → invalid. Ghi summary.txt: valid=<n> / invalid=<m> / max\_degree=<d>.|
|**Hướng dẫn:** |
|*Struct Poly { string id; int deg; vector<double> a; }.*|
|*Hàm: bool readPolysCSV(path, vector<Poly>&, int& invalid).*|
|*Case biên: degree=0 (hằng số); degree > số hệ số còn lại trong dòng.*|



|**Bài 2. Tính P(x) và ghi report [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|Đọc polynomials.csv và x\_values.csv. Tính P(x) bằng Horner cho mỗi đa thức hợp lệ. Ghi report.csv: id, x, P(x) (setprecision(6)). Cuối: valid\_count, invalid\_count.|
|**Hướng dẫn:** |
|*Horner: res=a[n]; for i=n-1 downto 0: res = res\*x + a[i].*|
|*Hàm: double evalHorner(vector<double>, double x).*|
|*Case biên: x\_values.csv rỗng → report chỉ có header + separator + counts.*|



|**Bài 3. Thống kê hệ số đa thức [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|Đọc polynomials.csv. Với mỗi đa thức hợp lệ, tính max|a\_i|, min|a\_i|, số hệ số = 0. Ghi stats.csv: id, degree, max\_abs, min\_abs, zero\_count.|
|**Hướng dẫn:** |
|*Duyệt hệ số: abs\_val = fabs(a[i]); so sánh để tìm max/min.*|
|*Case biên: degree=0 → 1 hệ số; nếu tất cả hệ số = 0 thì min\_abs=0.*|



|**Bài 4. Cộng hai đa thức [Trung bình** **]**   *Có hướng dẫn*|
| - |
|Đọc poly\_pairs.csv: mỗi dòng là 2 đa thức (id1,deg1,a0..an, id2,deg2,b0..bm). Tính tổng 2 đa thức (hệ số cộng theo lũy thừa tương ứng, bậc = max(deg1,deg2)). Ghi sum.csv: id, degree\_sum, c0..cm.|
|**Hướng dẫn:** |
|*Hàm: Poly addPoly(Poly p, Poly q): tạo vector hệ số dài max(p.deg,q.deg)+1.*|
|*Cộng từng hệ số, phần dài hơn giữ nguyên.*|
|*Case biên: 2 đa thức bậc 0; một đa thức rỗng.*|



|**Bài 5. Ma trận phân số: cộng và nhân [Trung bình** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc matA.csv và matB.csv (format: dòng đầu m n; mỗi ô num/den).</p><p>Tính A+B (nếu cùng kích thước) và A×B (nếu cols\_A = rows\_B). Normalize mọi kết quả.</p><p>Ghi result.csv: '=== A+B ===' hoặc 'INCOMPATIBLE'; '=== A\*B ===' hoặc 'INCOMPATIBLE'.</p>|
|**Hướng dẫn:** |
|*Hàm: bool addMatrix(FMatrix A, FMatrix B, FMatrix& C); bool mulMatrix(A, B, C).*|
|*Normalize sau mỗi addFrac/mulFrac để tránh hệ số phình quá lớn.*|
|*Case biên: 1×1 × 1×1; A+B với kích thước khác nhau.*|



|**Bài 6. Đạo hàm và đánh giá đa thức [Cơ bản** **]**  |
| - |
|Đọc polynomials.csv và x\_values.csv. Với mỗi đa thức hợp lệ, tính P'(x) tại mỗi x. Ghi deriv\_report.csv: id, x, P(x), dP(x) (cả giá trị gốc và đạo hàm).|



|**Bài 7. Tìm nghiệm nguyên của đa thức [Trung bình** **]**  |
| - |
|Đọc polynomials.csv. Với mỗi đa thức hệ số nguyên, tìm tất cả nghiệm nguyên x trong [-50, 50]. Ghi roots.csv: id, root (mỗi nghiệm 1 dòng). Nếu không có nghiệm → ghi 'id,NONE'.|



|**Bài 8. Ma trận đơn vị phân số [Trung bình** **]**  |
| - |
|Đọc n từ config. Tạo ma trận đơn vị n×n phân số (đường chéo = 1/1, còn lại = 0/1). Đọc ma trận A n×n phân số. Kiểm tra A × I = A và I × A = A (so sánh từng ô). Output: is\_identity\_product=1 hoặc 0.|



|**Bài 9. Đa thức Lagrange nội suy [Nâng cao** **]**  |
| - |
|<p>Đọc points.csv: n điểm (x\_i, y\_i) phân biệt (n ≤ 8). Tính đa thức nội suy Lagrange. Đánh giá tại các điểm trong query.csv. Ghi kết quả: x\_q, P(x\_q).</p><p>Ghi chú: không cần tính hệ số đa thức — chỉ cần P(x\_q) = Σ y\_i \* L\_i(x\_q).</p>|



|**Bài 10. Phân tích bình phương tổng [Nâng cao** **]**  |
| - |
|<p>Đọc fractions.csv. Tính tổng bình phương S = Σ (num\_i/den\_i)² và E[X²] - (E[X])²  (variance). Tất cả tính chính xác theo phân số (không dùng số thực).</p><p>Ghi stats.csv: sum\_squares=<num>/<den> / variance=<num>/<den>.</p>|
