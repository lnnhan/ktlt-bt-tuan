# ĐỀ BÀI TẬP TUẦN 4

**QUY ĐỊNH CHUNG!**

- Mọi bài bắt buộc áp dụng M0: phân tích → thiết kế hàm → kiểm thử.
- Missing: ô trống hoặc NA/NaN (không phân biệt hoa/thường). KHÔNG dùng -1 làm missing.
- Số thực: dùng fixed + setprecision theo đề (mặc định 6 nếu không ghi).
- Bắt buộc kiểm tra lỗi mở file (cerr + return 1 khi fail).
- Chạy ít nhất 2 bộ test (1 thường + 1 case biên) trước khi nộp.
- Khuyến nghị: GCC/MinGW. \_\_int128 KHÔNG dùng được trên MSVC (Visual Studio).

---

Kadane + LIS O(n²) + Tư duy dãy con 

5 bài Cơ bản/Trung bình (có hướng dẫn)   •   5 bài Không hướng dẫn

|**Bài 1. Max subarray sum (Kadane cơ bản) [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc mảng số nguyên. Tìm tổng lớn nhất của đoạn con liên tiếp.</p><p>Output: max\_sum=<v>.</p><p>Case biên bắt buộc: toàn số âm → max\_sum = phần tử lớn nhất (1 phần tử).</p>|
|**Hướng dẫn:** |
|*Khởi tạo bestEnding = bestSoFar = a[0].*|
|*Với i=1..n-1: bestEnding = max(a[i], bestEnding + a[i]); bestSoFar = max(bestSoFar, bestEnding).*|
|*Case biên: n=0 → in 'EMPTY'; n=1 → max\_sum = a[0].*|



|**Bài 2. Kadane có truy vết l, r [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Mở rộng Bài 1: tìm thêm chỉ số l, r (0-based) của đoạn tốt nhất. Output: max\_sum=<v> / l=<i> / r=<j>.</p><p>Nếu nhiều đoạn bằng nhau, chọn đoạn có l nhỏ nhất.</p>|
|**Hướng dẫn:** |
|*Theo dõi biến start (điểm bắt đầu hiện tại): khi a[i] > bestEnding+a[i] thì start=i.*|
|*Khi bestSoFar được cập nhật: lưu bestL=start, bestR=i.*|
|*Case biên: toàn âm → đoạn 1 phần tử là phần tử lớn nhất.*|



|**Bài 3. LIS độ dài O(n²) [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc mảng số nguyên. Tính độ dài dãy con tăng chặt dài nhất (LIS). Output: lis\_len=<v>.</p><p>Công thức: dp[i] = 1 + max{dp[j] : j<i và a[j]<a[i]}.</p>|
|**Hướng dẫn:** |
|*Khởi tạo dp[i]=1 cho mọi i. Hai vòng lặp lồng: O(n²).*|
|*Hàm cần viết: int lisLength(vector<int> a).*|
|*Case biên: n=0 → 0; n=1 → 1; mảng giảm dần → LIS=1.*|



|**Bài 4. Min subarray sum [Trung bình** **]**   *Có hướng dẫn*|
| - |
|Đọc mảng số nguyên. Tìm tổng nhỏ nhất của đoạn con liên tiếp (biến thể Kadane). Output: min\_sum=<v> / l=<i> / r=<j>.|
|**Hướng dẫn:** |
|*Kadane ngược: thay max bằng min, bestSoFar khởi tạo = a[0].*|
|*Hàm: KadaneAns minSubarray(vector<long long>).*|
|*Case biên: toàn dương → min = phần tử nhỏ nhất; toàn âm → min = tổng toàn mảng.*|



|**Bài 5. LIS truy vết dãy con [Trung bình** **]**   *Có hướng dẫn*|
| - |
|Mở rộng LIS: in ra chỉ số (0-based) của các phần tử trong dãy con tăng dài nhất.|
|Nếu nhiều LIS có độ dài bằng nhau, chọn LIS kết thúc ở chỉ số nhỏ nhất. Output: lis\_len=<v> / indices=<i0 i1 ...>.|
|**Hướng dẫn:** |
|*Mảng parent[i]: lưu chỉ số j trước i trong LIS (parent[i]=-1 nếu i là đầu).*|
|*Sau khi tính dp[], truy ngược từ vị trí có dp lớn nhất qua parent để lấy dãy chỉ số.*|
|*Case biên: LIS=1 → chỉ 1 chỉ số.*|



|**Bài 6. Đoạn có tổng lớn nhất độ dài đúng k [Cơ bản** **]**  |
| - |
|Đọc mảng và k. Tìm đoạn liên tiếp dài đúng k có tổng lớn nhất. Output: max\_sum=<v> / l=<i> / r=<j>. Nếu k>n in 'IMPOSSIBLE'.|



|**Bài 7. Kadane với nhiều bộ test [Trung bình** **]**  |
| - |
|<p>Đọc file multi\_test.txt gồm T bộ test. Mỗi bộ: dòng đầu là n, dòng sau là n số nguyên. Với mỗi bộ, in max subarray sum trên 1 dòng.</p><p>Đảm bảo không crash khi n=0 (in 'EMPTY').</p>|



|**Bài 8. Longest Non-Decreasing Subsequence [Trung bình** **]**  |
| - |
|<p>Đọc mảng số nguyên. Tính độ dài dãy con không giảm dài nhất (LNDS — cho phép bằng nhau). Phân biệt với LIS (tăng chặt): dp[i] = 1 + max{dp[j]: j<i và a[j] ≤ a[i]}.</p><p>Output: lnds\_len=<v>.</p>|



|**Bài 9. Maximum circular subarray [Nâng cao** **]**  |
| - |
|<p>Đọc mảng vòng tròn (phần tử sau a[n-1] là a[0]). Tìm đoạn con liên tiếp (theo vòng) có tổng lớn nhất.</p><p>Gợi ý: max\_circular = max(Kadane thường, total\_sum - min\_subarray\_sum).</p><p>Chú ý: nếu toàn số âm thì chỉ dùng Kadane thường (không dùng công thức vòng).</p>|



|**Bài 10. Đếm số dãy con tăng có độ dài = L [Nâng cao** **]**  |
| - |
|<p>Đọc mảng và L. Đếm số dãy con tăng chặt có đúng độ dài L (O(n²) là đủ). dp2[i][l] = số dãy con tăng độ dài l kết thúc tại i.</p><p>Output: count=<n>.</p>|
