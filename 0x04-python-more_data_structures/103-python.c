#include <stdio.h>
#include <Python.h>
/**
 * print_python_bytes - Prints bytes info
 *
 * @p: python Object
 * return: no return
 */
void print_python_bytes(PyObject *p)
{
	char *string;
	long int size, x, limit;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
{
	printf(" [ERROR] Invalid Bytes Object\n");
}

size = ((PyVarObject *)(p))->ob_size;
string = ((PyBytesObject *)p)->ob_sval;

printf(" size: %ld\n", size);
printf(" trying string: %s\n", string);

if (size >= 10)
	limit = 10
	else
	limit = size + 1;
	printf(" first %ld bytes:", limit);

	for (x = 0; x < limit; x++)
	if (string[x] >= 0)
	printf(" %02x", string[x]);
	else
	printf(" %02x", 256 + string[x]);
	printf("\n");
}
/**
 * print_python_list - Prints list info
 * @p: Python Object
 * return: no return
 */
void print_python_list(PyObject *p)
{
	long int size, x;
	PyListObject *list;
	PyObject *obj;

	size = ((PyVarObject *)(p))->ob_size;
	list = (PyListObject *)p;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocaated);

	for (x = 0; x < size; x++)
{
	obj = ((PyListObject *)p)->ob_item[x];
	printf("Element %ld: %s\n", x, ((obj)->_type)->tp_name);
	if (PyBytes_Check(obj))
		print_python_bytes(obj);
}

