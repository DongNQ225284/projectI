import psutil
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from datetime import datetime

# Khởi tạo danh sách lưu dữ liệu
cpu_data = []
ram_data = []
disk_data = []
time_data = []

# Số điểm tối đa hiển thị trên đồ thị
MAX_POINTS = 20

# Tên file log
LOG_FILE = "system_log.txt"

def get_stats():
    cpu = psutil.cpu_percent(interval=None)
    ram = psutil.virtual_memory().percent
    disk = psutil.disk_usage('/').percent
    return cpu, ram, disk

def log_stats(cpu, ram, disk):
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(LOG_FILE, 'a') as f:
        f.write(f"{now}\t| CPU: {cpu}%\t| RAM: {ram}%\t| Disk: {disk}%\n")

def update(frame):
    cpu, ram, disk = get_stats()
    log_stats(cpu, ram, disk)

    now = datetime.now().strftime("%H:%M:%S")
    if len(time_data) >= MAX_POINTS:
        time_data.pop(0)
        cpu_data.pop(0)
        ram_data.pop(0)
        disk_data.pop(0)

    time_data.append(now)
    cpu_data.append(cpu)
    ram_data.append(ram)
    disk_data.append(disk)

    plt.cla()  # xóa dữ liệu cũ trên đồ thị
    plt.plot(time_data, cpu_data, label='CPU (%)', color='red')
    plt.plot(time_data, ram_data, label='RAM (%)', color='blue')
    plt.plot(time_data, disk_data, label='Disk (%)', color='green')
    plt.ylim(0, 100)
    plt.xlabel("Time")
    plt.ylabel("Usage (%)")
    plt.title("Real-time System Resource Monitor")
    plt.legend()
    plt.xticks(rotation=45)
    plt.grid(True)
    plt.tight_layout()

# Tạo animation
ani = FuncAnimation(plt.gcf(), update, interval=1000)  # cập nhật mỗi 1 giây
plt.show()