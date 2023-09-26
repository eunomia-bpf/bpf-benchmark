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
bar_width = 0.10
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

selected_runtimes = ['./bpftime-ubpf', './bpftime-rbpf', './bpftime-llvm']

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

selected_runtimes = ['./bpftime-ubpf', './bpftime-rbpf', './bpftime-llvm', '<WASM>', "<NATIVE>"]

# Determine the number of rows and columns for subplots
num_tests = len(plot_data)
num_rows = (num_tests + 1) // 2
num_cols = 2 if num_tests > 1 else 1

fig, axes = plt.subplots(num_rows, num_cols, figsize=(20, 5 * num_rows))
if num_tests == 1:
    axes = np.array([axes])

# Plot Execution Usage
bar_width = 0.25
indices = np.arange(len(selected_runtimes))
colors = plt.cm.viridis(np.linspace(0, 1, len(selected_runtimes)))

for ax, (test_name, runtimes_data) in zip(axes.ravel(), plot_data.items()):
    
    values = [runtimes_data.get(exe, 0) for exe in selected_runtimes]
    bars = ax.bar(indices, values, width=bar_width, color=colors)
    
    ax.set_title(f"Execution Times for {test_name}", fontsize=16)
    ax.set_xlabel("Runtimes", fontsize=14)
    ax.set_ylabel("Execution Time", fontsize=14)
    ax.set_xticks(indices)
    ax.set_xticklabels(selected_runtimes, rotation=45, fontsize=12)
    ax.grid(True, which="both", ls="--", c="0.65")
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['bottom'].set_color('#DDDDDD')
    ax.spines['left'].set_color('#DDDDDD')
    ax.tick_params(bottom=False, left=False)
    ax.set_axisbelow(True)
    
    # Add legends (assuming you have more data for distribution)
    # ax.legend(bars, ["Runtime 1", "Runtime 2", ...], fontsize=12)

plt.tight_layout()
plt.savefig("merged_execution_times.png")
plt.show()