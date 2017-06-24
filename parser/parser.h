#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
namespace parser
{
enum CHECK_STATE
{
    CHECK_STATE_REQUESTLINE = 0,
    CHECK_STATE_HEADER
};
enum LINE_STATUS
{
    LINE_OK = 0,
    LINE_BAD,
    LINE_OPEN
};

enum HTTP_CODE
{
    NO_REQUEST,
    GET_REQUEST,
    BAD_REQUEST,
    FORBIDDEN_REQUEST,
    INTERNAL_ERROR,
    CLOSED_CONNECTION
};


class Parser
{

  public:
    Parser(int connectfd);
    ~Parser();
    HTTP_CODE parse_content();
    int recv_data_continue();

  public:
    int m_nSockfd;

    char m_nBuf[4096];
    int m_nReadIndex;
    int m_nCheckIndex;
    CHECK_STATE m_nCheckStat;

    int m_nLineStart;

    std::string m_nMethod;
    std::string m_nUrl;
    std::string m_nHttpVersion;
    std::string m_nHost;



    LINE_STATUS m_fParseLine();
    HTTP_CODE m_fParseRequestLine();
    HTTP_CODE m_fParseHeader();

    
};
}

#endif