
/*
#if (defined( __WIN32__ ) || defined( _WIN32 )) && !defined(CEGUI_STATIC)
#   ifdef CEGUIBASE_EXPORTS
#       define CEGUIEXPORT __declspec(dllexport)
#   else
#       define CEGUIEXPORT __declspec(dllimport)
#   endif
#       define CEGUIPRIVATE
#else
#       define CEGUIEXPORT
#       define CEGUIPRIVATE
#endif
*/

#   ifdef CEGUIBASE_EXPORTS
#       define CEGUIEXPORT __declspec(dllexport)
#   else
#       define CEGUIEXPORT __declspec(dllimport)
#   endif
#       define CEGUIPRIVATE


#include <exception>
#include <string>

class CEGUIEXPORT Exception : public std::exception
{
public:
    //! Virtual destructor.
    virtual ~Exception(void) throw();

    /*!
    \brief
        Return a reference to the String object describing the reason for the
        exception being thrown.
    \return
        String object containing a message describing the reason for the
        exception.
    */
    const std::string& getMessage(void) const
        { return d_message; }

    /*!
    \brief
        Return a reference to the String object containing the exception name
        (i.e. class type).
    \return
        String object containing the exception name.
    */
    const std::string& getName() const
        { return d_name; }

    /*!
    \brief
        Return a reference to the String object containing the name of the file
        where the exception occurred.
    \return
        String object containing the name of the file where the exception
        occurred.
    */
    const std::string& getFileName(void) const
        { return d_filename; }

    /*!
    \brief
        Return the line number where the exception occurred.
    \Return
        Integer representing the line number where the exception occurred.
    */
    int getLine(void) const
        { return d_line; }

    // override from std::exception.
    const char* what() const throw();

protected:
    /*!
    \brief
        Protected constructor that prevents instantiations (users should employ
        derived exception classes instead) and that is responsible for logging
        the exception.
    \param message
        String object describing the reason for the exception being thrown.
    \param name
        String object describing the exception class name
        (e.g. CEGUI::UnknownObjectException)
    \param filename
        String object containing the name of the file where the exception
        occurred.
    \param line
        Integer representing the line number where the exception occurred.
    */
    Exception(const std::string& message = "",
              const std::string& name = "CEGUI::Exception",
              const std::string& filename = "",
              int line = 0);

    //! Holds the reason for the exception being thrown.
    std::string d_message;
    //! Holds the name of the file where the exception occurred.
    std::string d_filename;
    //! Holds the class name of the exception (e.g. CEGUI::ObjectInUseException)
    std::string d_name;
    //! Holds the line number where the exception occurred.
    int d_line;
    //! Holds the default error message.
    std::string d_what;
};




//! Exception class used when some impossible request was made of the system.
class CEGUIEXPORT InvalidRequestException : public Exception
{
public:
    /*!
    \brief
        Constructor that is responsible for logging the invalid request
        exception by calling the base class.
    \param message
        String object describing the reason for the invalid request exception
        being thrown.
    \param filename
        String object containing the name of the file where the invalid request
        exception occurred.
    \param line
        Integer representing the line number where the invalid request exception
        occurred.
    \remarks
        The invalid request exception name is automatically passed to the base
        class as "CEGUI::InvalidRequestException".
    */
    InvalidRequestException(const std::string& message,
                            const std::string& file = "unknown", int line = 0) :
        Exception(message, "CEGUI::InvalidRequestException", file, line)
    {}
};




