/*!
 * \file
 * \brief Implémentation de la classe SvgAppender.
 */

#include "SvgAppender.hpp"

#include <list>
#include <thread>

logs::SvgAppender::SvgAppender(const std::string & filename) :
        ofs_(filename.c_str())
{
}

logs::SvgAppender::~SvgAppender()
{
    this->flush();
    lockMessages();
    ofs_.close();
    unlockMessages();
}

void logs::SvgAppender::writeMessage(const logs::Logger &, const logs::Level &, const std::string & message)
{
    logs::MemoryAppender::writeMessageOnly(message);
}

void logs::SvgAppender::flush()
{
    lockMessages();
    while (this->messages_.size() > 0) {
        std::string message = this->messages_.front();
        ofs_ << message << std::endl;
        this->messages_.pop_front();
        std::this_thread::yield();
    }
    unlockMessages();
    ofs_.flush();
}


