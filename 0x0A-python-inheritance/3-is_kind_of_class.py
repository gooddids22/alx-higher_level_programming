#!/usr/bin/python3
"""Defines a class and inherited class-checking function."""


def is_kind_of_class(obj, a_class):
    """Check if an object is an instance of, or is an inherited instance
    of a specified class.
    Args:
        obj (any): The object to check.
        a_class (type): The class to match the type of obj to.
    Returns:
        True - If obj is an instance or inherited instance of a_class
        False - Otherwise
    """
    if isinstance(obj, a_class):
        return True
    return False
