# ĐỀ BÀI TẬP TUẦN 6

**QUY ĐỊNH CHUNG!**

- Mọi bài bắt buộc áp dụng M0: phân tích → thiết kế hàm → kiểm thử.
- Missing: ô trống hoặc NA/NaN (không phân biệt hoa/thường). KHÔNG dùng -1 làm missing.
- Số thực: dùng fixed + setprecision theo đề (mặc định 6 nếu không ghi).
- Bắt buộc kiểm tra lỗi mở file (cerr + return 1 khi fail).
- Chạy ít nhất 2 bộ test (1 thường + 1 case biên) trước khi nộp.
- Khuyến nghị: GCC/MinGW. \_\_int128 KHÔNG dùng được trên MSVC (Visual Studio).

---

Ma trận 2D + Prefix Sum 2D 

5 bài Cơ bản/Trung bình (có hướng dẫn)   •   5 bài Không hướng dẫn

|**Bài 1. Tổng hàng và cột ma trận [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|Đọc ma trận m×n số nguyên từ matrix.txt. Tính tổng từng hàng và từng cột. Ghi row\_sums.txt và col\_sums.txt (mỗi dòng: i, tổng).|
|**Hướng dẫn:** |
|*Hàm: vector<long long> rowSums(matrix), colSums(matrix).*|
|*Case biên: ma trận 1×1; m=0 hoặc n=0 → file output rỗng.*|



|**Bài 2. Kiểm tra ma trận đối xứng [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|Đọc ma trận vuông n×n. Kiểm tra xem có đối xứng không (a[i][j]=a[j][i]). Output: is\_symmetric=1 hoặc 0. Nếu không vuông: is\_symmetric=0.|
|**Hướng dẫn:** |
|*Chỉ kiểm tra nửa trên (i<j) — O(n²/2).*|
|*Case biên: n=1 → luôn đối xứng; n=0 → đối xứng (ma trận rỗng).*|



|**Bài 3. Xây dựng prefix sum 2D [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc ma trận m×n. Xây dựng mảng pre2D.</p><p>Ghi pre2D ra file: mỗi dòng là 'i j pre[i][j]'.</p><p>Công thức: pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1].</p>|
|**Hướng dẫn:** |
|*Hàm: FMatrix buildPre2D(FMatrix a).*|
|*Xử lý biên: nếu i=0 thì pre[i-1][j]=0; nếu j=0 thì pre[i][j-1]=0.*|
|*Case biên: 1×1 → pre[0][0]=a[0][0].*|



|**Bài 4. Trả lời truy vấn tổng vùng [Trung bình** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc ma trận, xây prefix 2D, sau đó q truy vấn (x1,y1,x2,y2) từ file.</p><p>Trả lời O(1) mỗi truy vấn. In 'INVALID' nếu chỉ số sai hoặc x1>x2, y1>y2. Công thức sumRect: pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1].</p>|
|**Hướng dẫn:** |
|*Hàm: bool sumRect(pre, x1,y1,x2,y2, long long& ans).*|
|*Biên: x1=0 → pre[-1][…]=0; y1=0 → pre[…][-1]=0.*|
|*Case biên: truy vấn 1 ô (x1=x2, y1=y2) → sum = a[x1][y1].*|



|**Bài 5. Ma trận đường chéo [Trung bình** **]**   *Có hướng dẫn*||
| - | :- |
|<p>Đọc ma trận vuông n×n. Tính tổng đường chéo chính (i=j) và đường chéo phụ (i+j=n-1). Kiểm tra ma trận đường chéo: tất cả phần tử ngoài đường chéo chính bằng 0.</p><p>Output: main\_diag\_sum=<v> / anti\_diag\_sum=<v> / is\_diagonal=<0/1>.</p>||
|**Hướng dẫn:** ||
|*Vòng lặp: for i in 0..n-1: mainSum+=a[i][i]; antiSum+=a[i][n-1-i].*||
|*is\_diagonal: với mọi i≠j thì a[i][j]=0.*||
|*Case biên: n=1 → đường chéo chính = đường chéo phụ = a[0][0]; is\_diagonal=1.*||



|**Bài 6. Nhân hai ma trận [Trung bình** **]**  |
| - |
|<p>Đọc ma trận A (m×k) và B (k×n). Tính C = A×B.</p><p>Nếu kích thước không khớp (cols\_A ≠ rows\_B) → in 'INCOMPATIBLE'.</p><p>Ghi C ra output theo dạng: mỗi hàng là 1 dòng, các phần tử cách nhau bởi space.</p>|



|**Bài 7. Vùng con tổng lớn nhất (brute force) [Trung bình** **]**  |
| - |
|<p>Đọc ma trận m×n (m,n ≤ 50). Tìm vùng chữ nhật (x1,y1,x2,y2) có tổng lớn nhất. Dùng prefix 2D để tính tổng vùng O(1); duyệt tất cả O(m²n²).</p><p>Output: max\_sum, x1, y1, x2, y2.</p>|



|**Bài 8. Kiểm tra ma trận tam giác [Trung bình** **]**  |
| - |
|Đọc ma trận vuông n×n. Kiểm tra: (a) tam giác trên (a[i][j]=0 khi i>j); (b) tam giác dưới. Output: is\_upper=<0/1> / is\_lower=<0/1>.|



|**Bài 9. Xoay ma trận 90° theo chiều kim đồng hồ [Trung bình** **]**  |
| - |
|<p>Đọc ma trận m×n. Xoay 90° theo chiều kim đồng hồ: phần tử (i,j) → (j, m-1-i) trong ma trận n×m mới.</p><p>Ghi ma trận kết quả ra rotated.txt.</p>|



|**Bài 10. Đếm vùng con tổng bằng K [Nâng cao** **]**  |
| - |
|<p>Đọc ma trận m×n (m,n ≤ 100) và K. Đếm số vùng chữ nhật con có tổng đúng bằng K. Dùng prefix 2D + bài toán đếm subarray sum=K trên mỗi cặp hàng.</p><p>Output: count=<n>.</p>|
