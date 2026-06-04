import os
import subprocess

def convert_md_to_pdf(md_path):
    pdf_path = md_path.rsplit('.', 1)[0] + '.pdf'
    typ_path = md_path.rsplit('.', 1)[0] + '.typ'
    print(f"Converting: {md_path} -> {pdf_path}")
    
    try:
        # 1. Generate standalone Typst source with Arial (body) and Menlo (code)
        subprocess.run(["pandoc", md_path, "-s", "-V", "font=Arial", "-V", "codefont=Menlo", "-o", typ_path], check=True, capture_output=True)
        # 2. Compile to PDF with Typst (disabling tags to prevent compiler panic)
        subprocess.run(["typst", "compile", "--no-pdf-tags", typ_path, pdf_path], check=True, capture_output=True)
        print(f"Successfully converted {md_path}")
        success = True
    except subprocess.CalledProcessError as e:
        print(f"Error converting {md_path}:")
        print(e.stderr)
        success = False
    finally:
        if os.path.exists(typ_path):
            os.remove(typ_path)
    return success

def main():
    reports = [
        "Tuan01_Phantich&Baocao.md",
        "Tuan2/Tuan02_Baocao.md",
        "Tuan4/Tuan04_Baocao.md",
        "Tuan6/Tuan06_Baocao.md",
        "Tuan8/Tuan08_Baocao.md",
        "Tuan10/Tuan10_Baocao.md"
    ]
    
    success_count = 0
    for report in reports:
        if os.path.exists(report):
            if convert_md_to_pdf(report):
                success_count += 1
        else:
            print(f"Report file not found: {report}")
            
    print(f"\nDone! Converted {success_count}/{len(reports)} reports to PDF.")

if __name__ == "__main__":
    main()
