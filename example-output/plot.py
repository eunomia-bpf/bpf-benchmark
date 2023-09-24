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
