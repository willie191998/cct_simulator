# Component Circuit Simulator

### Author: Wilson Anorue

This repository contains a simple yet powerful component circuit simulator designed to derive the voltages and currents of various components within a circuit. The simulator is interactive, utilizing a native console interface to guide the user through the process of inputting circuit details.

## Principal
- **COncept**: Operates based on the principle of Simpsom's rule of discrete integration i.e. the value of each component is gotten at t=0 and integrated and infinitesimal integration of time to give a value at t=1, works in real-time. Different from other simulators like Spice which is based on Newton-Raphson method.
- 
## Features

- **Interactive Console Interface**: Users are prompted to enter the type of component, its value, any voltage or current sources, and the initial values of the components at t=0.
- **Supported Components**: 
  - Resistors (unlimited quantity)
  - One passive storage component (Inductor or Capacitor)
  - One source (either current or voltage)
- **Output**: The simulator generates a time stream of values that are written to a file. These can be plotted using Python's Matplotlib or MATLAB for graphical representation.

## Limitations

- **No Graphical Interface**: Currently, the simulator operates purely via the console. A web-based graphical interface is planned for future updates.
- **Component Restrictions**: The simulator can handle only one passive storage component (either an Inductor or a Capacitor) and one source (current or voltage).

## Future Development

This project is under active development to expand its capabilities. Planned improvements include the addition of a graphical user interface and support for more complex circuit configurations. It was originally first programmed in 2020 and has not been developed much since.

## Usage

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/willie191998/cct_simulator.git
    cd cct_simulator
    ```

2. **Run the Simulator**:
    ```bash
    g++ -o myprogram main.cpp
    ./myprogram
    ```

3. **Follow the On-Screen Prompts** to enter the component details and receive the output file.

## Output Visualization

To visualize the output, you can use Python's Matplotlib or MATLAB. Example scripts for plotting the output data are provided in the repository.

---

For any questions or contributions, feel free to open an issue or submit a pull request. Your feedback and contributions are highly appreciated!
