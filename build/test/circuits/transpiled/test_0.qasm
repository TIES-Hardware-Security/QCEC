OPENQASM 2.0;
include "qelib1.inc";
qreg q[53];
creg c[17];
u2(0.0,3.141592653589793) q[0];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];