# QPropertyMacro
Macros for simple use of Q_PROPERTY macros

Adding Properties to QObject based objects, is costly and cumbersome.

You have to add the following items to the class:

1. Q_PROPERTY statement
2. Declaration of getter and setter methods
3. Definition of getter and setter methods
4. Value changed signal definition
5. Member-Variable

To ease the usage of properties in QObject based objects,
you can use the macro defintions 

- Q_PROPERTY_FULL_VAL(property, type of property)
  Use this macro for simple data types (as integer, float etc).
  
- Q_PROPERTY_FULL_REF(property, type of property)
  Use this macro for object data types.
  The setter method will use reference instead of a copy
  
- Q_PROPERTY_READONLY(property, type of property)
  Use this macro for read only properties
  
Usage:
  See implemented tests as a sample for usage.
  
  
