/**
 * @file Logging.hpp
 * @author Ángel Talero (angelgotalero@outlook.com)
 * @brief Logging class
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021. Angel D. Talero
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

/**
 * @class Logging
 * @brief Output debug and log info
 * 
 */
class Logging
{
private:
    bool failure = false; /**< Failure flag*/
    std::string filename; /**< Filename */
    std::ofstream file;   /**< Ofstream file*/

public:
    /**
     * @enum InfoType
     * @brief Type of error
     */
    enum class InfoType
    {
        INFO,
        ERROR,
        WARNING
    };

public:
    /**
     * @brief Construct a new Logging object
     * 
     * @param filename File to write to
     * @param append Append to an existing file
     */
    Logging(std::string filename, bool append = true);

    /**
     * @brief Destroy the Logging object
     * 
     */
    ~Logging();

    /**
     * @brief Print to the log
     * 
     * @param service Name of the service
     * @param message Message to show
     * @param type Type of message
     */
    void print(std::string service, std::string message, InfoType type = InfoType::INFO);

    /**
     * @brief Check if initialization failed
     * 
     * @return true Initialization failed
     * @return false Initialization succeeded
     */
    bool isFailed();

public:
    /**
     * @brief Get the Date Time in the DD/MM/YYYY @ HH:MM:SS format
     * 
     * @return std::string Date time string
     */
    static std::string getDateTime();
};