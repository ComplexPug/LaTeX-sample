import os

folder_path = '.'
need_delete = ['.aux','.log','.gz','.toc']

for filename in os.listdir(folder_path):
    file_path = os.path.join(folder_path, filename)
    if os.path.isdir(file_path):
        continue
    ext = os.path.splitext(filename)[1]
    if ext in need_delete:
        os.remove(file_path)
    