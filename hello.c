#include <Python.h>

static PyObject* _hello_world(PyObject *self, PyObject *args) {
    return PyUnicode_FromString("Hello, world!");  // python c api
};

static struct PyMethodDef methods[] = {
    {"hello_world", (PyCFunction)_hello_world, METH_NOARGS},
    {NULL, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "hello",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_hello(void) {
    return PyModule_Create(&module);
}