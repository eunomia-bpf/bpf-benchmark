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

num_tests = len(plot_data)

# Plot Execution Usage
plt.figure(figsize=(15, 10))
bar_width = 0.10
total_width = num_tests * bar_width
indices = np.arange(len(executables))

for i, (name, values) in enumerate(plot_data.items()):
    plt.bar(indices + i * bar_width, values["exec_usage"], width=bar_width, label=name)

plt.title("Execution Usage for Different Tests Across Executables")
plt.xlabel("Executables")
plt.ylabel("Execution Usage (Time, Log Scale)")
plt.yscale("log")
plt.xticks(indices + total_width / 2 - bar_width / 2, executables, rotation=45)
plt.legend()
plt.grid(True, which="both", ls="--", c="0.65")
plt.tight_layout()
plt.savefig("execution_usage_bar_plot.png")

# Plot JIT Usage
plt.figure(figsize=(15, 10))

for i, (name, values) in enumerate(plot_data.items()):
    plt.bar(indices + i * bar_width, values["jit_usage"], width=bar_width, label=name)

plt.title("JIT Usage for Different Tests Across Executables")
plt.xlabel("Executables")
plt.ylabel("JIT Usage (Time, Log Scale)")
plt.yscale("log")
plt.xticks(indices + total_width / 2 - bar_width / 2, executables, rotation=45)
plt.legend()
plt.grid(True, which="both", ls="--", c="0.65")
plt.tight_layout()
plt.savefig("jit_usage_bar_plot.png")
