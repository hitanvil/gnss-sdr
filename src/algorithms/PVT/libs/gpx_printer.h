/*!
 * \file gpx_printer.h
 * \brief Interface of a class that prints PVT information to a gpx file
 * \author Álvaro Cebrián Juan, 2018. acebrianjuan(at)gmail.com
 *
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * -------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_GPX_PRINTER_H
#define GNSS_SDR_GPX_PRINTER_H


#include <fstream>
#include <string>

class Pvt_Solution;

/*!
 * \brief Prints PVT information to GPX format file
 *
 * See https://www.topografix.com/gpx.asp
 */
class Gpx_Printer
{
public:
    explicit Gpx_Printer(const std::string& base_path = ".");
    ~Gpx_Printer();
    bool set_headers(const std::string& filename, bool time_tag_name = true);
    bool print_position(const Pvt_Solution* position, bool print_average_values);
    bool close_file();

private:
    std::ofstream gpx_file;
    std::string gpx_filename;
    std::string indent;
    std::string gpx_base_path;
    bool positions_printed;
};

#endif
