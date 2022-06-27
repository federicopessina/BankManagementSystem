#pragma once
#include "View.h"
class ViewException :
    public View
{
public:
    /// <summary>
    /// Print to the user that the file have not been found.
    /// </summary>
    static void print_filenotfound_exception();
    /// <summary>
    /// Print to the user that the record inside the file have not been found.
    /// </summary>
    static void print_recordnotfound_exception();
};

