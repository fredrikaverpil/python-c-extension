#include <Python.h>

static PyObject *_hello_world(PyObject *self, PyObject *args) {
    // self is a reference to the c extension itself
    return PyUnicode_FromString("Hello, world!"); // google "python c api" for more info
};

static struct PyMethodDef methods[] = {
    // array of method definitions

    // method name, function pointer (cast to PyCFunction), flags
    {"hello_world", (PyCFunction)_hello_world, METH_NOARGS},
    {NULL, NULL}  // null terminated array
};

static struct PyModuleDef module = {
    // module definition
    PyModuleDef_HEAD_INIT,
    "hello",  // name matching the module in python
    NULL,
    -1,
    methods};

PyMODINIT_FUNC PyInit_hello(void) {
    // public initialization of the module, what is being called when importing the module
    return PyModule_Create(&module);
}