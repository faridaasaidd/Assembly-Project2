import matplotlib.pyplot as plt

# Data
scaling = [16, 32, 64, 128]
memgen1 = [93.75, 96.88, 98.44, 99.22]
memgen2 = [99.85, 99.92, 99.96, 99.98]
memgen3 = [0.10, 0.10, 0.10, 0.10]
memgen4 = [99.97, 99.99, 99.99, 100.00]
memgen5 = [99.59, 99.80, 99.90, 99.95]
memgen6 = [0.00, 0.00, 50.00, 75.00]

# Colors for each memory generator line
colors = ['blue', 'green', 'red', 'purple', 'orange', 'brown']

# Create a new figure
plt.figure(figsize=(12, 8))

# Plot each memory generator's data with labels
def plot_with_labels(x, y, label, color):
    plt.plot(x, y, label=label, marker='o', color=color)
    for i, txt in enumerate(y):
        plt.annotate(f'{txt:.2f}%', (x[i], y[i]), textcoords="offset points",
                     xytext=(0,10), ha='center', color=color)

plot_with_labels(scaling, memgen1, 'Memgen1', colors[0])
plot_with_labels(scaling, memgen2, 'Memgen2', colors[1])
plot_with_labels(scaling, memgen3, 'Memgen3', colors[2])
plot_with_labels(scaling, memgen4, 'Memgen4', colors[3])
plot_with_labels(scaling, memgen5, 'Memgen5', colors[4])
plot_with_labels(scaling, memgen6, 'Memgen6', colors[5])

# Adding title and labels
plt.title('Cache Hit Ratios for Different Memory Generators')
plt.xlabel('Line Size (bytes)')
plt.ylabel('Hit Ratio (%)')

# Set y-axis limits and custom ticks
plt.ylim(99, 100)
plt.yticks([i for i in range(99, 100)])

# Add grid
plt.grid(True)

# Add legend
plt.legend()

# Show the plot
plt.show()
