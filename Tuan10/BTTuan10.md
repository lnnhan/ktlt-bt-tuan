# ĐỀ BÀI TẬP TUẦN 10

**QUY ĐỊNH CHUNG!**

- Mọi bài bắt buộc áp dụng M0: phân tích → thiết kế hàm → kiểm thử.
- Missing: ô trống hoặc NA/NaN (không phân biệt hoa/thường). KHÔNG dùng -1 làm missing.
- Số thực: dùng fixed + setprecision theo đề (mặc định 6 nếu không ghi).
- Bắt buộc kiểm tra lỗi mở file (cerr + return 1 khi fail).
- Chạy ít nhất 2 bộ test (1 thường + 1 case biên) trước khi nộp.
- Khuyến nghị: GCC/MinGW. \_\_int128 KHÔNG dùng được trên MSVC (Visual Studio).

---

Tổng hợp M0: Mini-project + Module hoá 

5 bài Cơ bản/Trung bình (có hướng dẫn)   •   5 bài Không hướng dẫn



|**Bài 1. Pipeline M0 hoàn chỉnh: CSV Cleaning [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc data.csv (id, value). Missing: NA/blank. Tính mean bỏ missing; impute missing = mean; tính Z-score.</p><p>Ghi report.csv: id, value\_imputed, zscore (setprecision(6)). Ghi summary.txt: count\_valid, count\_missing, mean, std.</p>|
|**Hướng dẫn:** |
|*Tách thành 3 hàm rõ ràng: parseCSV(), computeStats(), imputeAndScore().*|
|*Z-score: z = (x - mean) / std; nếu std=0 → z=0.*|
|*Case biên: tất cả missing → mean=0, std=0, mọi z=0.*|



|**Bài 2. Fraction List tổng hợp [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc fractions.csv. Lọc invalid, normalize, sort tăng, tính tổng.</p><p>Ghi fraction\_out.csv: valid\_count, invalid\_count, sum; sau đó danh sách đã sort. Bắt buộc: tách thành ít nhất 4 hàm (read, filter+normalize, sort, write).</p>|
|**Hướng dẫn:** |
|*Hàm: readFractions(), filterAndNormalize(), sortFractions(), writeFractionReport().*|
|*Đảm bảo sum được tính bằng addFrac (phân số chính xác, không dùng double).*|
|*Case biên: không có phân số hợp lệ → sum=0/1.*|



|**Bài 3. Polynomial records + evaluate [Cơ bản** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc polynomials.csv và x\_values.csv. Tính P(x) bằng Horner. Ghi report.csv: id,x,P(x). Cuối: valid/invalid count.</p><p>Bắt buộc: tách module io (readPoly, readX, writeReport) và processing (evalHorner).</p>|
|**Hướng dẫn:** |
|*Kiểm tra kỹ: degree<0 → invalid; thiếu hệ số → 0; x\_values rỗng → OK.*|
|*Hàm writeReport phải ghi đúng format: header + data + --- + counts.*|
|*Dùng setprecision(6) cho mọi số thực trong output.*|



|**Bài 4. Multi-query prefix sum tổng hợp [Trung bình** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc mảng, sau đó 3 loại truy vấn: 'SUM l r' (tổng đoạn), 'AVG l r' (trung bình), 'CNT l r v' (đếm phần tử = v).</p><p>Ghi kết quả từng truy vấn. In 'INVALID' nếu chỉ số sai. Bắt buộc: mỗi loại truy vấn là 1 hàm riêng.</p>|
|**Hướng dẫn:** |
|*SUM: dùng prefix sum long long. AVG: SUM / (r-l+1).*|
|*CNT: dùng prefix count riêng cho từng giá trị (hoặc brute force O(n) mỗi truy vấn nếu n≤1000).*|
|*Hàm: handleSUM(), handleAVG(), handleCNT().*|


|**Bài 5. Text analysis pipeline [Trung bình** **]**   *Có hướng dẫn*|
| - |
|<p>Đọc text.txt và stopwords.txt. Pipeline: normalize → tokenize → lọc stop-words → đếm → top-20. Ghi freq.csv (top-20) và summary.txt (total, unique, top-5 dạng bảng).</p><p>Bắt buộc: ít nhất 5 hàm riêng. Chạy đúng với file rỗng và file chỉ stop-words.</p>|
|**Hướng dẫn:** |
|*Hàm: readText(), normalize(), tokenize(), filterStopWords(), countFreq(), writeFreq(), writeSummary().*|
|*Case biên: sau khi lọc stop-words không còn token → freq.csv chỉ có header.*|
|*Dùng setw + left để căn lề bảng trong summary.txt.*|



|**Bài 6. Dashboard tổng hợp 1 file [Trung bình** **]**  |
| - |
|<p>Đọc data.csv (id, value1, value2, ..., valueN — N cột số, có thể missing).</p><p>Với mỗi cột: tính count, missing, min, max, mean, std. Ghi dashboard.csv (1 hàng = 1 cột thống kê).</p><p>Tổ chức theo M0: 1 hàm cho mỗi bước, gọi từ main().</p>|



|**Bài 7. Sliding window multi-stat [Trung bình** **]**  |
| - |
|<p>Đọc mảng số thực và k. Tính cả 3 chỉ số trong 1 lần duyệt: rolling mean, rolling max, rolling min. Ghi multi\_rolling.csv: i, mean\_i, max\_i, min\_i (setprecision(6)).</p><p>Bắt buộc: mỗi loại rolling là 1 hàm riêng.</p>|



|**Bài 8. Sort + search tổng hợp [Trung bình** **]**  |
| - |
|<p>Đọc records.csv (id, score). Đọc queries.txt: mỗi dòng là 1 id cần tra.</p><p>Sắp xếp records theo score giảm (stable sort). Với mỗi query: tìm record và in rank (1-based), id, score.</p><p>Nếu id không tồn tại: in 'NOT\_FOUND'.</p>|



|**Bài 9. Phát hiện outlier IQR [Nâng cao** **]**  |
| - |
|<p>Đọc values.csv (1 cột số thực, không missing). Tính Q1, Q3, IQR = Q3-Q1.</p><p>Outlier: x < Q1 - 1.5\*IQR hoặc x > Q3 + 1.5\*IQR.</p><p>Ghi outliers.csv: index, value. Ghi summary: Q1, Q3, IQR, n\_outliers (setprecision(6)).</p>|



|**Bài 10. Mini-project tự do: chọn 1 [Nâng cao** **]**  |
| - |
|<p>Chọn 1 trong 3 hướng và hoàn thiện theo M0 đầy đủ với ≥ 4 file module:</p><p>Hướng A (KHDL): Đọc dataset nhiều cột → cleaning → normalize Z-score → xuất report + histogram chữ ASCII.</p><p>Hướng B (Toán): Đọc ma trận phân số → kiểm tra đối xứng, tam giác → nhân → xuất với định dạng đẹp.</p><p>Hướng C (Text): Pipeline đầy đủ normalize → tokenize → TF-IDF → xuất top-10 từ và similarity 2 file.</p><p>Nộp kèm: checklist M0, README, ≥ 2 bộ test (1 thường + 1 biên).</p>|
