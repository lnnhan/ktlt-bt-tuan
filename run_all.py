import os
import subprocess

base_dir = '/Users/giabao/Desktop/HCMUS/KTLT/BT_hang-tuan'
weeks = ['Tuan2', 'Tuan4', 'Tuan6', 'Tuan8', 'Tuan10']
exercises = [f'Bai{i:02d}' for i in range(1, 11)]

results = []

for week in weeks:
    for ex in exercises:
        target_dir = os.path.join(base_dir, week, ex)
        main_cpp = os.path.join(target_dir, 'main.cpp')
        
        if not os.path.exists(main_cpp):
            continue
            
        print(f"[{week} - {ex}] Compiling...")
        compile_cmd = ['clang++', '-Wall', '-O0', 'main.cpp', '-o', 'out']
        compile_proc = subprocess.run(compile_cmd, cwd=target_dir, capture_output=True, text=True)
        
        if compile_proc.returncode != 0:
            print(f"[{week} - {ex}] COMPILATION FAILED")
            results.append((week, ex, "COMPILE_ERROR", compile_proc.stderr))
            continue
            
        print(f"[{week} - {ex}] Running...")
        try:
            run_proc = subprocess.run(['./out'], cwd=target_dir, capture_output=True, text=True, timeout=3)
            if run_proc.returncode == 0:
                print(f"[{week} - {ex}] SUCCESS")
                results.append((week, ex, "SUCCESS", run_proc.stdout))
            else:
                print(f"[{week} - {ex}] RUNTIME ERROR")
                results.append((week, ex, "RUNTIME_ERROR", run_proc.stderr))
        except subprocess.TimeoutExpired:
            print(f"[{week} - {ex}] TIMEOUT")
            results.append((week, ex, "TIMEOUT", "Execution took more than 3 seconds. Might be waiting for user input."))

# Write summary report
summary_path = os.path.join(base_dir, 'Execution_Summary.md')
with open(summary_path, 'w', encoding='utf-8') as f:
    f.write("# TỔNG HỢP KẾT QUẢ CHẠY TEST CÁC BÀI TẬP\n\n")
    for week, ex, status, out in results:
        f.write(f"## {week} - {ex} ({status})\n")
        f.write("```text\n")
        f.write(out.strip() if out.strip() else "(No output)")
        f.write("\n```\n\n")

print(f"\nSaved summary to {summary_path}")
