#include <Python.h>

static PyObject *_hello_world(PyObject *self)
{
    // self is a reference to the c extension itself
    return PyUnicode_FromString("hello world"); // google "python c api" for more info
};

static PyObject *_greet(PyObject *self, PyObject *args)
{

    PyObject *name;

    if (!PyArg_ParseTuple(args, "U", &name))
    {
        return NULL;
    }

    // allocate new object which sets its reference count to 1
    PyObject *upper = PyObject_CallMethod(name, "upper", NULL);

    if (!upper)
    {
        return NULL;
    }

    PyObject *ret = PyUnicode_FromFormat("hello %U", upper);
    Py_DECREF(upper); // decrement reference count to avoid leaking memory
    return ret;
}

static struct PyMethodDef methods[] = {
    // array of method definitions

    // method name, function pointer (cast to PyCFunction), flags
    {"hello_world", (PyCFunction)_hello_world, METH_NOARGS},
    {"greet", (PyCFunction)_greet, METH_NOARGS},
    {NULL, NULL} // null terminated array
};

static struct PyModuleDef module = {
    // module definition
    PyModuleDef_HEAD_INIT,
    "hello", // name matching the module in python
    NULL,
    -1,
    methods};

PyMODINIT_FUNC PyInit_hello(void)
{
    // public initialization of the module, what is being called when importing the module
    return PyModule_Create(&module);
}
