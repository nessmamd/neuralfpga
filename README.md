# neural fpga (working code is in weightFactory)
### next steps are applying it to the fpga and creating seperate files for each class 

This project implements a basic neural network with multiple layers in C++. The network reads data from a CSV file from a simple feed-forward neural network using PyTorch to classify images of handwritten digits from the MNIST dataset. The model has two hidden layers and uses the ReLU activation function, trained with the Adam optimizer and Cross-Entropy Loss, applies weights and biases to inputs using the sigmoid activation function, and processes multiple layers to produce an output.

### Features for C++ code
#### CSV Parsing: Reads weights and biases from a CSV file.
#### Neural Network Layers: Implements multiple layers, each with weights and biases, and applies the sigmoid activation function.
#### Layer Processing: Computes outputs based on provided inputs.
#### Classification: Chooses the best possible outcome from the computed results.

### Features for PyTorch code
#### Neural Network Architecture:
Input layer (784 units, corresponding to 28x28 images)
Two hidden layers (128 and 64 units)
Output layer (10 units, one for each digit class)
#### MNIST Dataset: Handwritten digit images from 0 to 9.
#### Training and Evaluation: The network is trained on 60,000 training samples and evaluated on 10,000 test samples.
#### Weights and Biases Export: The model's weights and biases are saved to a CSV file after training.
