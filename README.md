## Getting Started

QCEC is available via [PyPI](https://pypi.org/project/mqt.qcec/) for Linux, macOS, and Windows.

```console
(venv) $ pip install mqt.qcec
```

The following code gives an example on the usage:

```python3
from mqt import qcec

# verify the equivalence of two circuits provided as qasm files
result = qcec.verify("circ1.qasm", "circ2.qasm")

# print the result
print(result.equivalence)
```

**Detailed documentation on all available methods, options, and input formats is available at [ReadTheDocs](https://qcec.readthedocs.io/en/latest/).**

## System Requirements and Building

The implementation is compatible with any C++17 compiler and a minimum CMake version of 3.14.
Please refer to the [documentation](https://qcec.readthedocs.io/en/latest/) on how to build the project.

Building (and running) is continuously tested under Linux, macOS, and Windows using the [latest available system versions for GitHub Actions](https://github.com/actions/virtual-environments).


The modified version does not support python extensions. Therefore, to compile the file use the command 
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_QCEC_TESTS=ON -DBINDINGS=ON
cmake --build build --config Release
And the package will compile based on the modification of the source code. 

To run the modified version. Run the file in qcec/build/test/qcec_test and the file will execute with the position_match strategy with 20 different benchmark circuits.
