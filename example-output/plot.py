import matplotlib.pyplot as plt
import json
import numpy as np

# Given data
data_str = ""  # Place your JSON data between the triple quotes
with open("data.json", "r") as f:
    data_str = f.read()
data = json.loads(data_str)

# Data Preparation
executables = data["executables"]
results = data["results"]

# Prepare the plot data
plot_data = {}
for exe, exe_results in zip(executables, results):
    for test in exe_results:
        if test["name"] not in plot_data:
            plot_data[test["name"]] = {"exec_usage": [], "jit_usage": []}
        plot_data[test["name"]]["exec_usage"].append(test["exec_usage"])
        plot_data[test["name"]]["jit_usage"].append(test["jit_usage"])

num_runtimes = len(executables)

# Plot Execution Usage
plt.figure(figsize=(15, 10))
bar_width = 0.20
total_width = num_runtimes * bar_width
indices = np.arange(len(plot_data))

for i, exe in enumerate(executables):
    exec_usages = [plot_data[test_name]["exec_usage"][i] for test_name in plot_data]
    plt.bar(indices + i * bar_width, exec_usages, width=bar_width, label=exe)

plt.title("Execution Usage for Different Tests Across Runtimes")
plt.xlabel("Test Cases")
plt.ylabel("Execution Usage (Time in nanoseconds, Log Scale)")
plt.yscale("log")
plt.xticks(indices + total_width / 2 - bar_width / 2, plot_data.keys(), rotation=45)
plt.legend()
plt.grid(True, which="both", ls="--", c="0.65")
plt.tight_layout()
plt.savefig("execution_usage_bar_plot.png")

# Plot JIT Usage
plt.figure(figsize=(15, 10))

for i, exe in enumerate(executables):
    jit_usages = [plot_data[test_name]["jit_usage"][i] for test_name in plot_data]
    plt.bar(indices + i * bar_width, jit_usages, width=bar_width, label=exe)

plt.title("JIT Usage for Different Tests Across Runtimes")
plt.xlabel("Test Cases")
plt.ylabel("JIT Usage (Time in nanoseconds, Log Scale)")
plt.yscale("log")
plt.xticks(indices + total_width / 2 - bar_width / 2, plot_data.keys(), rotation=45)
plt.legend()
plt.grid(True, which="both", ls="--", c="0.65")
plt.tight_layout()
plt.savefig("jit_usage_bar_plot.png")
# Given data
data_str = ""  # Place your JSON data between the triple quotes
with open("data.json", "r") as f:
    data_str = f.read()
data = json.loads(data_str)

# Data Preparation
executables = data["executables"]
results = data["results"]

# Prepare the plot data
plot_data = {}
for exe, exe_results in zip(executables, results):
    for test in exe_results:
        if test["name"] not in plot_data:
            plot_data[test["name"]] = {}
        plot_data[test["name"]][exe] = test["exec_usage"]

selected_runtimes = ['ubpf-jit', 'rbpf-jit', 'llvm-jit']

# Plot Execution Usage
bar_width = 0.25
indices = np.arange(len(selected_runtimes))

for test_name, runtimes_data in plot_data.items():
    plt.figure(figsize=(10, 7))
    
    values = [runtimes_data.get(exe, 0) for exe in selected_runtimes]
    plt.bar(indices, values, width=bar_width)
    
    plt.title(f"Execution Times for {test_name}")
    plt.xlabel("Runtimes")
    plt.ylabel("Execution Time")
    plt.xticks(indices, selected_runtimes, rotation=45)
    plt.grid(True, which="both", ls="--", c="0.65")
    plt.tight_layout()
    plt.savefig(f"execution_times_for_{test_name}.png")
    plt.close()
# Given data
data_str = ""  # Place your JSON data between the triple quotes
with open("data.json", "r") as f:
    data_str = f.read()
data = json.loads(data_str)

# Data Preparation
executables = data["executables"]
results = data["results"]

# Prepare the plot data
plot_data = {}
for exe, exe_results in zip(executables, results):
    for test in exe_results:
        if test["name"] not in plot_data:
            plot_data[test["name"]] = {}
        plot_data[test["name"]][exe] = test["exec_usage"]
selected_runtimes = ['ubpf-jit', 'rbpf-jit', 'llvm-jit', '<WASM>', "<NATIVE>"]

# 确定子图的行和列数
num_tests = len(plot_data)
num_rows = 1
num_cols = num_tests

# 设置更大的图表尺寸以提高可读性
fig, axes = plt.subplots(num_rows, num_cols, figsize=(20, 6))
if num_tests == 1:
    axes = np.array([axes])
bar_width = 0.8 # 适当减小条形宽度以增加空间
indices = np.arange(len(selected_runtimes))
colors = plt.cm.tab10(np.linspace(0, 1, len(selected_runtimes))) # 使用tab10颜色图提供更好的颜色对比

i = 0

for ax, (test_name, runtimes_data) in zip(axes.ravel(), plot_data.items()):

    values = [runtimes_data.get(exe, 0) for exe in selected_runtimes]

    # 更新显示名称
    display_names = [exe.replace('llvm-jit', 'llvm jit') for exe in selected_runtimes]

    bars = ax.bar(indices, values, width=bar_width, color=colors)
     # 只在第一个子图上添加Y轴标签和网格线
    if i == 0:
        ax.set_ylabel("Execution Time(ns)", fontsize=18)
        ax.grid(True, which="both", ls="--", c="0.8")
        i = 1
    else:
        ax.grid(False)  # 其他子图不显示网格线
        

    # 添加数据标签
    # for bar in bars:
    #     height = bar.get_height()
    #     ax.annotate(f'{height:.0f}',
    #                 xy=(bar.get_x() + bar.get_width() / 2, height),
    #                 xytext=(0, 3),  # 3点偏移
    #                 textcoords="offset points",
    #                 ha='center', va='bottom')

    ax.set_title(f"{test_name.replace('_', ' ').title()}", fontsize=18)
    # ax.set_xticks(indices)
    # ax.set_xticklabels(display_names, rotation=45, fontsize=14)
    # ax.grid(True, which="both", ls="--", c="0.8") # 更轻的网格线
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['left'].set_color('#DDDDDD')
    ax.spines['bottom'].set_color('#DDDDDD')
    # ax.tick_params(bottom=False, left=False)
    ax.set_axisbelow(True)
    # ax.set_ylabel("Execution Time", fontsize=16)

# 自动调整子图间距，确保标签和标题不会重叠
plt.tight_layout(pad=3.0)

# 可以选择将图例放在图表下方
handles = [plt.Rectangle((0,0),1,1, color=colors[i]) for i in range(len(selected_runtimes))]
labels = [name.replace('llvm-jit', 'llvm jit') for name in selected_runtimes]
plt.legend(handles, labels, bbox_to_anchor=(0.5, -0.03), loc='upper right',
           ncol=len(selected_runtimes), frameon=False, fontsize=18)

plt.savefig("jit_execution_times.png")
plt.show()
