#ifndef WriterVersion_CC
#define WriterVersion_CC

#include<string>

namespace PRISMS
{
    std::string IntegrationToolsWriter_version_id()
    {
        return "VERSION_ID";
    }
    
    std::string IntegrationToolsWriter_commit_id()
    {
        return "COMMIT_ID";
    }
    
    std::string IntegrationToolsWriter_repo_url()
    {
        return "REPO_URL";
    }
}

#endif
