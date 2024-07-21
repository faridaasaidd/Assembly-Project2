import matplotlib.pyplot as plt

# Data
scaling = [16, 32, 64, 128]
# Data for DM
"""
memgen1 = [93.75, 96.875, 98.4375, 99.2187]
memgen2 = [99.8464, 99.9232, 99.9616, 99.9808]
memgen3 = [0.0986, 0.0998, 0.0972, 0.0965]
memgen4 = [99.9744, 99.9872, 99.9936, 99.9968]
memgen5 = [99.5904, 99.7952, 99.8976, 99.9488]
memgen6 = [0, 0, 49.9999, 74.9999]
"""
# Data for FA

memgen1 = [93.75, 96.875, 98.4375, 99.2187]
memgen2 = [99.8097, 99.9022, 99.9525, 99.9767]
memgen3 = [0.10,0.0986, 0.0996, 0.098]
memgen4 = [99.9731, 99.9865, 99.9933, 99.9966]
memgen5 = [98.5682, 99.2797, 99.6639, 99.8248]
memgen6 = [20.0801, 1.9648, 50.9807, 75.4829]

# Colors for each memory generator line
colors = ['blue', 'green', 'red', 'purple', 'orange', 'brown']

# Create a new figure
plt.figure(figsize=(12, 8))

# Plot each memory generator's data without labels but with increased line thickness
def plot_with_labels(x, y, label, color):
    plt.plot(x, y, label=label, marker='o', color=color, linewidth=1)

plot_with_labels(scaling, memgen1, 'Memgen1', colors[0])
plot_with_labels(scaling, memgen2, 'Memgen2', colors[1])
plot_with_labels(scaling, memgen3, 'Memgen3', colors[2])
plot_with_labels(scaling, memgen4, 'Memgen4', colors[3])
plot_with_labels(scaling, memgen5, 'Memgen5', colors[4])
plot_with_labels(scaling, memgen6, 'Memgen6', colors[5])

# Adding title and labels
plt.title('Fully Associative Cache Hit Ratios by Different Memory Generators ')
plt.xlabel('Line Size (bytes)')
plt.ylabel('Hit Ratio (%)')

plt.ylim(93.7, 100.5)
# Add grid
plt.grid(True)

# Add legend
plt.legend()

# Show the plot
plt.show()
