/******************************************************************************
 *
 * 
 *
 * Copyright (C) 1997-2008 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */
/*
==================================================================================
Suomenkielinen k‰‰nnˆs:
Olli Korhonen      <olli.korhonen@ccc.fi>
Antti Laine        <antti.a.laine@tut.fi>
==================================================================================
1999/10/19
*  Alustava k‰‰nnˆs valmis.

*  Huom: Kaikille termeille on keksitty k‰‰nnˆsvastine, mik‰ ei ehk‰ ole 
         kaikissa tapauksissa hyv‰ ratkaisu, ja parempikin termi voi 
         olla vakiintuneessa k‰ytˆss‰.

* Teht‰v‰‰: 
        - Termien kokoaminen listaksi ja suomennosten j‰rkevyyden tarkastelu. (lista on jo melko kattava)
                Author          = Tekij‰
                Class           = Luokka
                Compound        = Kooste
                Data            = Data
                Documentation   = Dokumentaatio
                Defines         = M‰‰rittelyt
                Description     = Selite
                Detailed        = Yksityiskohtainen
                Diagram         = Kaavio
                Enum            = Enumeraatio / Luettelotyyppi
                Exceptions      = Poikkeukset
                File            = Tiedosto
                Friends         = Yst‰v‰t
                Functions       = Funktiot
                Hierarchical    = Hierarkinen
                Index           = Indeksi
                Inherits        = Perii
                Member          = J‰sen
                Module          = Moduli
                Namespace       = Nimiavaruus
                Parameters      = Parametrit
                Private         = Yksityinen
                Protected       = Suojattu
                Prototypes      = Prototyypit
                Public          = Julkinen
                Reference Manual= K‰sikirja
                Reimplemented   = Uudelleen toteutettu
                Related         = Liittyv‰
                Signals         = Signaalit
                Slots           = Vastineet
                Static          = Staattinen
                Struct          = Tietue
                Typedef         = Tyyppim‰‰rittely
                Union           = Yhdiste
                Variables       = Muuttujat
        - Taivutusmuotojen virheettˆmyyden tarkastelu prepositioiden korvauskohdissa.
        - Sanasta sanaan k‰‰nnˆskohtien mielekkyyden tarkastelu valmiista dokumentista.
        - umlaut vastineiden k‰yttˆ scandien kohdalla.

positiiviset kommentit otetaan ilolla vastaan.
===================================================================================
*/

#ifndef TRANSLATOR_FI_H
#define TRANSLATOR_FI_H

class TranslatorFinnish : public TranslatorEnglish
{
  public:
    /*! This method is used to generate a warning message to signal
     *  the user that the translation of his/her language of choice
     *  needs updating.
     */
    virtual QCString updateNeededMessage()
    {
      return "Warning: The Finnish translator is really obsolete.\n"
             "It was not updated since version 1.0.0.  As a result,\n"
             "some sentences may appear in English.\n\n";
    }
    
    // --- Language control methods -------------------
    
    /*! Used for identification of the language. The identification 
     * should not be translated. It should be replaced by the name 
     * of the language in English using lower-case characters only
     * (e.g. "czech", "japanese", "russian", etc.). It should be equal to 
     * the identification used in language.cpp.
     */
    QCString idLanguage()
    { return "finnish"; }

    /*! Used to get the LaTeX command(s) for the language support. 
     *  This method should return string with commands that switch
     *  LaTeX to the desired language.  For example 
     *  <pre>"\\usepackage[german]{babel}\n"
     *  </pre>
     *  or
     *  <pre>"\\usepackage{polski}\n"
     *  "\\usepackage[latin2]{inputenc}\n"
     *  "\\usepackage[T1]{fontenc}\n"
     *  </pre>
     * 
     * The English LaTeX does not use such commands.  Because of this
     * the empty string is returned in this implementation.
     */
    virtual QCString latexLanguageSupportCommand()
    {
      return "\\usepackage[finnish}{babel}"
             "\\usepackage[latin1]{inputenc}"
             "\\usepackage[T1]{fontenc}";
    }

    /*! return the language charset. This will be used for the HTML output */
    virtual QCString idLanguageCharset()
    {
      return "iso-8859-1";
    }

    // --- Language translation methods -------------------

    /*! used in the compound documentation before a list of related functions. */
    QCString trRelatedFunctions()
    { return "Liittyv‰t funktiot"; } // "Related Functions";

    /*! subscript for the related functions. */
    QCString trRelatedSubscript()
    { return "(Huomaa, ett‰ n‰m‰ eiv‰t ole j‰senfunktioita.)"; } // "(Note that these are not member functions.)"

    /*! header that is put before the detailed description of files, classes and namespaces. */
    QCString trDetailedDescription()
    { return "Yksityiskohtainen selite"; } // "Detailed Description"

    /*! header that is put before the list of typedefs. */
    QCString trMemberTypedefDocumentation()
      // header that is put before the list of typedefs.
    { return "J‰sentyyppim‰‰rittelyiden dokumentaatio"; } // "Member Typedef Documentation"

    /*! header that is put before the list of enumerations. */
    QCString trMemberEnumerationDocumentation()
    { return "J‰senenumeraatioiden dokumentaatio"; } // "Member Enumeration Documentation"

    /*! header that is put before the list of member functions. */
    QCString trMemberFunctionDocumentation()
    { return "J‰senfunktioiden dokumentaatio"; } // "Member Function Documentation"

    /*! header that is put before the list of member attributes. */
    virtual QCString trMemberDataDocumentation()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Kenttien dokumentaatio"; // "Field Documentation"; 
      }
      else
      {
        return "J‰sendatan dokumentaatio"; // "Member Data Documentation"
      }
    }

    /*! this is the text of a link put after brief descriptions. */
    QCString trMore()
    { return "Lis‰‰..."; } // "More..."

     /*! put in the class documentation */
    QCString trListOfAllMembers()
    { return "Lista kaikista j‰senist‰."; } // "List of all members."
    QCString trMemberList()

    /*! used as the title of the "list of all members" page of a class */
    { return "J‰senlista"; } // "Member List"

    /*! this is the first part of a sentence that is followed by a class name */
    QCString trThisIsTheListOfAllMembers()
    { return "T‰m‰ on lista kaikista j‰senist‰"; } // "This is the complete list of members for "

    /*! this is the remainder of the sentence after the class name */
    QCString trIncludingInheritedMembers()
    { return ", sis‰lt‰en kaikki perityt j‰senet."; } // ", including all inherited members."

    /*! this is put at the author sections at the bottom of man pages.
     *  parameter s is name of the project name.
     */
    QCString trGeneratedAutomatically(const char *s)
    { QCString result="Automaattisesti generoitu Doxygenilla "
                      "l‰hdekoodista projektille "+s"; // "Generated automatically by Doxygen" ... "for" ... "from the sourcecode"
      //if (s) result+=(QCString)" voor "+s;
      // t‰ss‰ on ongelma, kuinka taivuttaa parametria, esim. "Jcad"+"in"; "IFC2VRML konversio"+"n"
      // mutta ratkaistaan ongelma k‰tev‰sti kaksoispisteell‰ -> "Jcad:n" / "IFC2VRML konversio:n"
      // lopputulos on v‰hemm‰n kˆkkˆ ja t‰ysin luettava, mutta ei kuitenkaan t‰ydellinen.
      //
      // kierret‰‰n ongelma taivuttamalla sanaa projekti :)
      return result;
    }

    /*! put after an enum name in the list of all members */
    QCString trEnumName()
    { return "enumeraation nimi"; } // "enum name"

    /*! put after an enum value in the list of all members */
    QCString trEnumValue()
    { return "enumeraation arvo"; } // "enum value"

    /*! put after an undocumented member in the list of all members */
    QCString trDefinedIn()
    { return "m‰‰ritelty"; } // "defined in"

    // quick reference sections

    /*! This is put above each page as a link to the list of all groups of 
     *  compounds or files (see the \\group command).
     */
    QCString trModules()
    { return "Moduulit"; } // "Modules"
    
    /*! This is put above each page as a link to the class hierarchy */
    QCString trClassHierarchy()
    { return "Luokkahierarkia"; } // "Class Hierarchy"
   
    /*! This is put above each page as a link to the list of annotated classes */ 
    QCString trCompoundList()
    virtual QCString trCompoundList()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueet"; // "Data Structures"
      }
      else
      {
        return "Luokkalista"; // "Class List"
      }
    }

    /*! This is put above each page as a link to the list of documented files */
    QCString trFileList()
    { return "Tiedostolista"; } // "File List"
   
    /*! This is put above each page as a link to all members of compounds. */ 
    virtual QCString trCompoundMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueen kent‰t"; // "Data Fields" 
      }
      else
      {
        return "Luokan j‰senet"; // "Class Members"
      }
    }
    
    /*! This is put above each page as a link to all members of files. */
    virtual QCString trFileMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Globaalit"; // "Globals" 
      }
      else
      {
        return "Tiedoston j‰senet"; // "File Members"
      }
    }

    /*! This is put above each page as a link to all related pages. */
    QCString trRelatedPages()
    { return "Liittyv‰t sivut"; } // "Related Pages"
   
    /*! This is put above each page as a link to all examples. */ 
    QCString trExamples()
    { return "Esimerkit"; } // "Examples"
   
    /*! This is put above each page as a link to the search engine. */ 
    QCString trSearch()
    { return "Etsi"; } // "Search"
   
    /*! This is an introduction to the class hierarchy. */ 
    QCString trClassHierarchyDescription()
    { return "T‰m‰ periytymislista on p‰‰tasoltaan aakkostettu " // "This inheritance list is sorted roughly, "
             "mutta alij‰senet on aakkostettu itsen‰isesti:"; // "but not completely, alphabetically:";
    }

    /*! This is an introduction to the list with all files. */
    QCString trFileListDescription(bool extractAll)
    {
      QCString result="T‰‰ll‰ on lista kaikista ";
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      result+="tiedostoista lyhyen selitteen kera:"; // "files with brief descriptions:"
      return result;
    }
    
    /*! This is an introduction to the annotated compound list. */
    QCString trCompoundListDescription()
    {
    
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "T‰ll‰ ovat tietueet lyhyen selitteen kera:"; // "Here are the data structures with brief descriptions:"
      }
      else
      {
        return "T‰‰ll‰ ovat luokat, tietueet ja " // "Here are the classes, structs and "
             "yhdisteet lyhyen selitteen kera:"; // "unions with brief descriptions:"
      }
    }
    
    /*! This is an introduction to the page with all class members. */
    QCString trCompoundMembersDescription(bool extractAll)
    {
      {
      QCString result="T‰‰ll‰ on lista kaikista " // "Here is a list of all "
      if (!extractAll)
      {
        result+="dokumentoiduista "; // "documented "
      }
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="tietuiden ja yhdisteiden kentist‰"; // "struct and union fields"
      }
      else
      {
        result+="luokkien j‰senist‰"; // "class members"
      }
      result+=" linkitettyin‰ "; // " with links to "
      if (!extractAll) 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+="jokaisen kent‰n tietueen/yhdisteen dokumentaatioon:"; // "the struct/union documentation for each field:"
        }
        else
        {
          result+="jokaisen j‰senen luokkadokumentaatioon:"; // "the class documentation for each member:"
        }
      }
      else 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+= "tietueisiin/yhdisteisiin, joihin ne kuuluvat:"; // "the structures/unions they belong to:"
        }
        else
        {
          result+="luokkiin, joihin ne kuuluvat"; //"the classes they belong to:"
        }
      }
      return result;
    }

    /*! This is an introduction to the page with all file members. */
    QCString trFileMembersDescription(bool extractAll)
    {
      QCString result="T‰‰ll‰ on lista kaikista "; // "Here is a list of all "
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="funktioista, muuttujista, m‰‰rittelyist‰, luetteloista ja tyyppim‰‰rittelyist‰"; // "functions, variables, defines, enums, and typedefs"
      }
      else
      {
        result+="tiedoston j‰senist‰"; // "file members"
      }
      result+=" linkitettyin‰ "; // " with links to "
      if (extractAll) 
        result+="tiedostoon, johon ne kuuluvat:"; // "the files they belong to:"
      else 
        result+="dokumentaatioon:"; // "the documentation:"
      return result;
    }
    
    /*! This is an introduction to the page with the list of all examples */
    QCString trExamplesDescription()
    { return "T‰‰ll‰ on lista kaikista esimerkeist‰:"; } //  "Here is a list of all examples:"
   
    /*! This is an introduction to the page with the list of related pages */ 
    QCString trRelatedPagesDescription()
    { return "T‰‰ll‰ on lista kaikista liittyvist‰ dokumentaatiosivuista:"; } // "Here is a list of all related documentation pages:"
   
    /*! This is an introduction to the page with the list of class/file groups */ 
    QCString trModulesDescription()
    { return "T‰‰ll‰ on lista kaikista moduleista:"; } // "Here is a list of all modules:"
    
    // index titles (the project name is prepended for these) 
    
    /*! This is used in HTML as the title of index.html. */
    QCString trDocumentation()
    { return "Dokumentaatio"; } // "Documentation"
    
    /*! This is used in LaTeX as the title of the chapter with the 
     * index of all groups.
     */
    QCString trModuleIndex()
    { return "Moduuliluettelo"; } // "Module Index"
    
    /*! This is used in LaTeX as the title of the chapter with the 
     * class hierarchy.
     */
    QCString trHierarchicalIndex()
    { return "Hierarkinen luettelo"; } // "Hierarchical Index"
    
    /*! This is used in LaTeX as the title of the chapter with the 
     * annotated compound index.
     */
    QCString trCompoundIndex()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      { 
        return "Tietueluettelo"; // "Data Structure Index"
      }
      else
      {
        return "Luokkaluettelo"; // "Class Index"
      }
    }
    
    /*! This is used in LaTeX as the title of the chapter with the
     * list of all files.
     */
    QCString trFileIndex() 
    { return "Tiedostoluettelo"; } // "File Index"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all groups.
     */
    QCString trModuleDocumentation()
    { return "Moduulin dokumentaatio"; } // "Module Documentation"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all classes, structs and unions.
     */
    QCString trClassDocumentation()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueen dokumentaatio"; // "Data Structure Documentation"
      }
      else
      {
        return "Luokan dokumentaatio"; // "Class Documentation"
      }
    }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all files.
     */
    QCString trFileDocumentation()
    { return "Tiedoston dokumentaatio"; } // "File Documentation"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all examples.
     */
    QCString trExampleDocumentation()
    { return "Esimerkkien dokumentaatio"; } // "Example Documentation"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all related pages.
     */
    QCString trPageDocumentation()
    { return "Sivujen dokumentaatio"; } // "Page Documentation"
    
    /*! This is used in LaTeX as the title of the document */
    QCString trReferenceManual()
    { return "K‰sikirja"; } // "Reference Manual"

    /*! This is used in the documentation of a file as a header before the 
     *  list of defines
     */
    QCString trDefines()
    { return "M‰‰rittelyt"; } // "Defines"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of function prototypes
     */
    QCString trFuncProtos()
    { return "Funktioiden prototyypit"; } // "Function Prototypes"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of typedefs
     */
    QCString trTypedefs()
    { return "Tyyppim‰‰rittelyt"; } // "Typedefs"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of enumerations
     */
    QCString trEnumerations()
    { return "Luettelotyypit"; } // "Enumerations"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) functions
     */
    QCString trFunctions()
    { return "Funktiot"; } // "Functions"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    QCString trVariables()
    { return "Muuttujat"; } // "Variables"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    QCString trEnumerationValues()
    { return "Luettelotyyppien arvot"; } // "Enumerator"

    /*! This is used in the documentation of a file before the list of
     *  documentation blocks for defines
     */
    QCString trDefineDocumentation()
    { return "M‰‰ritysten dokumentointi"; } // "Define Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for function prototypes
     */
    QCString trFunctionPrototypeDocumentation()
    { return "Funktioprototyyppien dokumentaatio"; } // "Function Prototype Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for typedefs
     */
    QCString trTypedefDocumentation()
    { return "Tyyppim‰‰ritysten dokumentaatio"; } // "Typedef Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration types
     */
    QCString trEnumerationTypeDocumentation()
    { return "Luettelotyyppien dokumentaatio"; } // "Enumeration Type Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for functions
     */
    QCString trFunctionDocumentation()
    { return "Funktioiden dokumentaatio"; } // "Function Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for variables
     */
    QCString trVariableDocumentation()
    { return "Muuttujien dokumentaatio"; } // "Variable Documentation"
    
    /*! This is used in the documentation of a file/namespace/group before 
     *  the list of links to documented compounds
     */
    QCString trCompounds()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueet"; // "Data Structures"
      }
      else
      {
        return "Luokat"; // "Classes"
      }
    }
    
    /*! This is used in the standard footer of each page and indicates when 
     *  the page was generated 
     */
    QCString trGeneratedAt(const char *date,const char *projName)
    { 
        // funktio on hiukan vaikea k‰‰nt‰‰ prepositioihin sidotun rakenteen vuoksi.
      QCString result=(QCString)"Generoitu "+date; // "Generated on "
      if (projName) result+=(QCString)" projektille "+projName; // " for "
      result+=(QCString)" tekij‰: "; // " by"
      return result;
    }
    /*! This is part of the sentence used in the standard footer of each page.
     */
    QCString trWrittenBy()
    {
      return "kirjoittanut"; // "written by"
    }

    /*! this text is put before a class diagram */
    QCString trClassDiagram(const char *clName)
    {
      return "Luokan "+(QCString)clName+" luokkakaavio"; // "Inheritance diagram for "
    }

    /*! this text is generated when the \\internal command is used. */
    QCString trForInternalUseOnly()
    { return "Vain sis‰iseen k‰yttˆˆn."; } // "For internal use only."
    
    /*! this text is generated when the \\warning command is used. */
    QCString trWarning()
    { return "Varoitus"; } // "Warning"
    
    /*! this text is generated when the \\version command is used. */
    QCString trVersion()
    { return "Versio"; } // "Version"
    
    /*! this text is generated when the \\date command is used. */
    QCString trDate()
    { return "P‰iv‰ys"; } // "Date"
    
    /*! this text is generated when the \\return command is used. */
    QCString trReturns()
    { return "Palauttaa"; } // "Returns"
    
    /*! this text is generated when the \\sa command is used. */
    QCString trSeeAlso()
    { return "Katso myˆs"; } // "See also"
    
    /*! this text is generated when the \\param command is used. */
    QCString trParameters()
    { return "Parametrit"; } // "Parameters"
    
    /*! this text is generated when the \\exception command is used. */
    QCString trExceptions()
    { return "Poikkeukset"; } // "Exceptions"
    
    /*! this text is used in the title page of a LaTeX document. */
    QCString trGeneratedBy()
    { return "Generoinut"; } // "Generated by"
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990307 
//////////////////////////////////////////////////////////////////////////
    
    /*! used as the title of page containing all the index of all namespaces. */
    QCString trNamespaceList()
    { return "Nimiavaruus Lista"; } // "Namespace List"
    
    /*! used as an introduction to the namespace list */
    QCString trNamespaceListDescription(bool extractAll)
    {
      QCString result="T‰‰ll‰ on lista kaikista "; // "Here is a list of all "
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      result+="nimiavaruuksista lyhyen selitteen kera:"; // "namespaces with brief descriptions:"
      return result;
    }
    
    /*! used in the class documentation as a header before the list of all
     *  friends of a class
     */
    QCString trFriends()
    { return "Yst‰v‰t"; } // "Friends"

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990405
//////////////////////////////////////////////////////////////////////////
    
    /*! used in the class documentation as a header before the list of all
     * related classes 
     */
    QCString trRelatedFunctionDocumentation()
    { return "Yst‰v‰t ja niihin liittyvien funktioiden dokumentaatio"; } // "Friends And Related Function Documentation"
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990425
//////////////////////////////////////////////////////////////////////////

    /*! used as the title of the HTML page of a class/struct/union */
    virtual QCString trCompoundReference(const char *clName,
                                    ClassDef::CompoundType compType,
                                    bool isTemplate)
    {
      QCString result=(QCString)clName;
      switch(compType)
      {
        case ClassDef::Class:      result+=" Luokka"; break; // " Class"
        case ClassDef::Struct:     result+=" Tietue"; break; // " Struct"
        case ClassDef::Union:      result+=" Yhdiste"; break; // " Union"
        case ClassDef::Interface:  result+=" Rajapinta"; break; // " Interface"
        case ClassDef::Protocol:   result+=" Protokolla"; break; // " Protocol"
        case ClassDef::Category:   result+=" Kategoria"; break; // " Category"
        case ClassDef::Exception:  result+=" Poikkeus"; break; // " Exception"
      }
      if (isTemplate) result+=" Malli"; // " Template"
      result+=" Referenssi"; // " Reference"
      return result;
    }

    /*! used as the title of the HTML page of a file */
    virtual QCString trFileReference(const char *fileName)
    {
      QCString result=fileName;
      result+=" Tiedostoreferenssi"; // " File Reference"
      return result;
    }
    
    /*! used as the title of the HTML page of a namespace */
    virtual QCString trNamespaceReference(const char *namespaceName)
    {
      QCString result=namespaceName;
      result+=" Nimiavaruusreferenssi"; // " Namespace Reference"
      return result;
    }
    
    virtual QCString trPublicMembers()
    { return "Julkiset j‰senfunktiot"; } // "Public Member Functions"
    virtual QCString trPublicSlots()
    { return "Julkiset vastineet"; } // "Public Slots"
    virtual QCString trSignals()
    { return "Signaalit"; } // "Signals"
    virtual QCString trStaticPublicMembers()
    { return "Staattiset julkiset j‰senfunktiot"; } // "Static Public Member Functions"
    virtual QCString trProtectedMembers()
    { return "Suojatut j‰senfunktiot"; } // "Protected Member Functions"
    virtual QCString trProtectedSlots()
    { return "Suojatut vastineet"; } // "Protected Slots"
    virtual QCString trStaticProtectedMembers()
    { return "Staattiset suojatut j‰senfunktiot"; } // "Static Protected Member Functions"
    virtual QCString trPrivateMembers()
    { return "Yksityiset j‰senfunktiot"; } // "Private Member Functions"
    virtual QCString trPrivateSlots()
    { return "Yksityiset vastineet"; } // "Private Slots"
    virtual QCString trStaticPrivateMembers()
    { return "Staattiset yksityiset j‰senfunktiot"; } // "Static Private Member Functions"

    /*! this function is used to produce a comma-separated list of items.
     *  use generateMarker(i) to indicate where item i should be put.
     */
    QCString trWriteList(int numEntries)
    {
      QCString result;
      int i;
      // the inherits list contain `numEntries' classes
      for (i=0;i<numEntries;i++) 
      {
        // use generateMarker to generate placeholders for the class links!
        result+=generateMarker(i); // generate marker for entry i in the list 
                                   // (order is left to right)
        
        if (i!=numEntries-1)  // not the last entry, so we need a separator
        {
          if (i<numEntries-2) // not the fore last entry 
            result+=", ";
          else                // the fore last entry
            result+=" ja "; // ", and "
        }
      }
      return result; 
    }
    
    /*! used in class documentation to produce a list of base classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritsList(int numEntries)
    {
      return "Perij‰t "+trWriteList(numEntries)+"."; // "Inherits "
    }
    
    /*! used in class documentation to produce a list of super classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritedByList(int numEntries)
    {
      return "Periytyy "+trWriteList(numEntries)+"."; // "Inherited by "
    }
    
    /*! used in member documentation blocks to produce a list of 
     *  members that are hidden by this one.
     */
    virtual QCString trReimplementedFromList(int numEntries)
    {
      return "Uudelleen toteutettaa "+trWriteList(numEntries)+"."; // "Reimplemented from "
    }
    
    /*! used in member documentation blocks to produce a list of
     *  all member that overwrite the implementation of this member.
     */
    virtual QCString trReimplementedInList(int numEntries)
    {
      return "Uudelleen toteutettu "+trWriteList(numEntries)+"."; // "Reimplemented in "
    }

    /*! This is put above each page as a link to all members of namespaces. */
    virtual QCString trNamespaceMembers()
    { return "Nimiavaruuden j‰senet"; } // "Namespace Members"
    
    /*! This is an introduction to the page with all namespace members */
    virtual QCString trNamespaceMemberDescription(bool extractAll)
    { 
      QCString result="T‰‰ll‰ on lista kaikista "; // "Here is a list of all "
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      result+="nimiavaruuden j‰senist‰ linkitettyn‰ "; // "namespace members with links to "
      if (extractAll) 
        result+="nimiavaruuden dokumentaatioon johon ne kuuluvat:"; // "the namespace documentation for each member:";
      else 
        result+="nimiavaruuksiin joihin ne kuuluvat:"; // "the namespaces they belong to:"
      return result;
    }
    /*! This is used in LaTeX as the title of the chapter with the 
     *  index of all namespaces.
     */ 
    virtual QCString trNamespaceIndex()
    { return "Nimiavaruuksien luettelo"; } // "Namespace Index"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all namespaces.
     */
    virtual QCString trNamespaceDocumentation()
    { return "Nimiavaruuden dokumentaatio"; } // "Namespace Documentation"
};

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990522
//////////////////////////////////////////////////////////////////////////

    /*! This is used in the documentation before the list of all
     *  namespaces in a file.
     */
    virtual QCString trNamespaces()
    { return "Nimiavaruudet"; } // "Namespaces"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990728
//////////////////////////////////////////////////////////////////////////

    /*! This is put at the bottom of a class documentation page and is
     *  followed by a list of files that were used to generate the page.
     */
    virtual QCString trGeneratedFromFiles(ClassDef::CompoundType compType,
        bool single)
    { // here s is one of " Class", " Struct" or " Union"
      // single is true implies a single file
      QCString result=(QCString)"The documentation for this ";
      switch(compType)
      {
        case ClassDef::Class:      result+="class"; break;
        case ClassDef::Struct:     result+="struct"; break;
        case ClassDef::Union:      result+="union"; break;
        case ClassDef::Interface:  result+="interface"; break;
        case ClassDef::Protocol:   result+="protocol"; break;
        case ClassDef::Category:   result+="category"; break;
        case ClassDef::Exception:  result+="exception"; break;
      }
      result+=" was generated from the following file";
      if (single) result+=":"; else result+="s:";
      return result;
    }

    /*! This is in the (quick) index as a link to the alphabetical compound
     * list.
     */
    virtual QCString trAlphabeticalList()
    { return "Alphabetical List"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990901
//////////////////////////////////////////////////////////////////////////

    /*! This is used as the heading text for the retval command. */
    virtual QCString trReturnValues()
    { return "Return values"; }

    /*! This is in the (quick) index as a link to the main page (index.html)
     */
    virtual QCString trMainPage()
    { return "Main Page"; }

    /*! This is used in references to page that are put in the LaTeX 
     *  documentation. It should be an abbreviation of the word page.
     */
    virtual QCString trPageAbbreviation()
    { return "p."; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991003
//////////////////////////////////////////////////////////////////////////

    virtual QCString trDefinedAtLineInSourceFile()
    {
      return "Definition at line @0 of file @1.";
    }
    virtual QCString trDefinedInSourceFile()
    {
      return "Definition in file @0.";
    }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991205
//////////////////////////////////////////////////////////////////////////

    virtual QCString trDeprecated()
    {
      return "Deprecated";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.0.0
//////////////////////////////////////////////////////////////////////////

    /*! this text is put before a collaboration diagram */
    virtual QCString trCollaborationDiagram(const char *clName)
    {
      return (QCString)"Collaboration diagram for "+clName+":";
    }
    /*! this text is put before an include dependency graph */
    virtual QCString trInclDepGraph(const char *fName)
    {
      return (QCString)"Include dependency graph for "+fName+":";
    }
    /*! header that is put before the list of constructor/destructors. */
    virtual QCString trConstructorDocumentation()
    {
      return "Constructor & Destructor Documentation"; 
    }
    /*! Used in the file documentation to point to the corresponding sources. */
    virtual QCString trGotoSourceCode()
    {
      return "Go to the source code of this file.";
    }
    /*! Used in the file sources to point to the corresponding documentation. */
    virtual QCString trGotoDocumentation()
    {
      return "Go to the documentation of this file.";
    }
    /*! Text for the \\pre command */
    virtual QCString trPrecondition()
    {
      return "Precondition";
    }
    /*! Text for the \\post command */
    virtual QCString trPostcondition()
    {
      return "Postcondition";
    }
    /*! Text for the \\invariant command */
    virtual QCString trInvariant()
    {
      return "Invariant";
    }
    /*! Text shown before a multi-line variable/enum initialization */
    virtual QCString trInitialValue()
    {
      return "Initial value:";
    }
    /*! Text used the source code in the file index */
    virtual QCString trCode()
    {
      return "code";
    }
    virtual QCString trGraphicalHierarchy()
    {
      return "Graphical Class Hierarchy";
    }
    virtual QCString trGotoGraphicalHierarchy()
    {
      return "Go to the graphical class hierarchy";
    }
    virtual QCString trGotoTextualHierarchy()
    {
      return "Go to the textual class hierarchy";
    }
    virtual QCString trPageIndex()
    {
      return "Page Index";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.0
//////////////////////////////////////////////////////////////////////////
    
    virtual QCString trNote()
    {
      return "Note";
    }
    virtual QCString trPublicTypes()
    {
      return "Public Types";
    }
    virtual QCString trPublicAttribs()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Data Fields";
      }
      else
      {
        return "Public Attributes";
      }
    }
    virtual QCString trStaticPublicAttribs()
    {
      return "Static Public Attributes";
    }
    virtual QCString trProtectedTypes()
    {
      return "Protected Types";
    }
    virtual QCString trProtectedAttribs()
    {
      return "Protected Attributes";
    }
    virtual QCString trStaticProtectedAttribs()
    {
      return "Static Protected Attributes";
    }
    virtual QCString trPrivateTypes()
    {
      return "Private Types";
    }
    virtual QCString trPrivateAttribs()
    {
      return "Private Attributes";
    }
    virtual QCString trStaticPrivateAttribs()
    {
      return "Static Private Attributes";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.3
//////////////////////////////////////////////////////////////////////////

    /*! Used as a marker that is put before a \\todo item */
    virtual QCString trTodo()
    {
      return "Todo";
    }
    /*! Used as the header of the todo list */
    virtual QCString trTodoList()
    {
      return "Todo List";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.4
//////////////////////////////////////////////////////////////////////////

    virtual QCString trReferencedBy()
    {
      return "Referenced by";
    }
    virtual QCString trRemarks()
    {
      return "Remarks";
    }
    virtual QCString trAttention()
    {
      return "Attention";
    }
    virtual QCString trInclByDepGraph()
    {
      return "This graph shows which files directly or "
             "indirectly include this file:";
    }
    virtual QCString trSince()
    {
      return "Since";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.1.5
//////////////////////////////////////////////////////////////////////////

    /*! title of the graph legend page */
    virtual QCString trLegendTitle()
    {
      return "Graph Legend";
    }
    /*! page explaining how the dot graph's should be interpreted 
     *  The %A in the text below are to prevent link to classes called "A".
     */
    virtual QCString trLegendDocs()
    {
      return 
        "This page explains how to interpret the graphs that are generated "
        "by doxygen.<p>\n"
        "Consider the following example:\n"
        "\\code\n"
        "/*! Invisible class because of truncation */\n"
        "class Invisible { };\n\n"
        "/*! Truncated class, inheritance relation is hidden */\n"
        "class Truncated : public Invisible { };\n\n"
        "/* Class not documented with doxygen comments */\n"
        "class Undocumented { };\n\n"
        "/*! Class that is inherited using public inheritance */\n"
        "class PublicBase : public Truncated { };\n\n"
        "/*! A template class */\n"
        "template<class T> class Templ { };\n\n"
        "/*! Class that is inherited using protected inheritance */\n"
        "class ProtectedBase { };\n\n"
        "/*! Class that is inherited using private inheritance */\n"
        "class PrivateBase { };\n\n"
        "/*! Class that is used by the Inherited class */\n"
        "class Used { };\n\n"
        "/*! Super class that inherits a number of other classes */\n"
        "class Inherited : public PublicBase,\n"
        "                  protected ProtectedBase,\n"
        "                  private PrivateBase,\n"
        "                  public Undocumented,\n"
        "                  public Templ<int>\n"
        "{\n"
        "  private:\n"
        "    Used *m_usedClass;\n"
        "};\n"
        "\\endcode\n"
        "If the \\c MAX_DOT_GRAPH_HEIGHT tag in the configuration file "
        "is set to 240 this will result in the following graph:"
        "<p><center><img alt=\"\" src=\"graph_legend."+Config_getEnum("DOT_IMAGE_FORMAT")+"\"></center>\n"
        "<p>\n"
        "The boxes in the above graph have the following meaning:\n"
        "<ul>\n"
        "<li>%A filled gray box represents the struct or class for which the "
        "graph is generated.\n"
        "<li>%A box with a black border denotes a documented struct or class.\n"
        "<li>%A box with a grey border denotes an undocumented struct or class.\n"
        "<li>%A box with a red border denotes a documented struct or class for"
        "which not all inheritance/containment relations are shown. %A graph is "
        "truncated if it does not fit within the specified boundaries.\n"
        "</ul>\n"
        "The arrows have the following meaning:\n"
        "<ul>\n"
        "<li>%A dark blue arrow is used to visualize a public inheritance "
        "relation between two classes.\n"
        "<li>%A dark green arrow is used for protected inheritance.\n"
        "<li>%A dark red arrow is used for private inheritance.\n"
        "<li>%A purple dashed arrow is used if a class is contained or used "
        "by another class. The arrow is labeled with the variable(s) "
        "through which the pointed class or struct is accessible.\n"
        "<li>%A yellow dashed arrow denotes a relation between a template instance and "
        "the template class it was instantiated from. The arrow is labeled with "
        "the template parameters of the instance.\n"
        "</ul>\n";
    }
    /*! text for the link to the legend page */
    virtual QCString trLegend()
    {
      return "legend";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.2.0
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a test item */
    virtual QCString trTest()
    {
      return "Test";
    }
    /*! Used as the header of the test list */
    virtual QCString trTestList()
    {
      return "Test List";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.1
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for KDE-2 IDL methods */
    virtual QCString trDCOPMethods()
    {
      return "DCOP Member Functions";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.2
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for IDL properties */
    virtual QCString trProperties()
    {
      return "Properties";
    }
    /*! Used as a section header for IDL property documentation */
    virtual QCString trPropertyDocumentation()
    {
      return "Property Documentation";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.4
//////////////////////////////////////////////////////////////////////////

    /*! Used for Java classes in the summary section of Java packages */
    virtual QCString trClasses()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Data Structures";
      }
      else
      {
        return "Classes";
      }
    }
    /*! Used as the title of a Java package */
    virtual QCString trPackage(const char *name)
    {
      return (QCString)"Package "+name;
    }
    /*! Title of the package index page */
    virtual QCString trPackageList()
    {
      return "Package List";
    }
    /*! The description of the package index page */
    virtual QCString trPackageListDescription()
    {
      return "Here are the packages with brief descriptions (if available):";
    }
    /*! The link name in the Quick links header for each page */
    virtual QCString trPackages()
    {
      return "Packages";
    }
    /*! Text shown before a multi-line define */
    virtual QCString trDefineValue()
    {
      return "Value:";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.2.5
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a \\bug item */
    virtual QCString trBug()
    {
      return "Bug";
    }
    /*! Used as the header of the bug list */
    virtual QCString trBugList()
    {
      return "Bug List";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.6
//////////////////////////////////////////////////////////////////////////

    /*! Used as ansicpg for RTF file 
     * 
     * The following table shows the correlation of Charset name, Charset Value and 
     * <pre>
     * Codepage number:
     * Charset Name       Charset Value(hex)  Codepage number
     * ------------------------------------------------------
     * DEFAULT_CHARSET           1 (x01)
     * SYMBOL_CHARSET            2 (x02)
     * OEM_CHARSET             255 (xFF)
     * ANSI_CHARSET              0 (x00)            1252
     * RUSSIAN_CHARSET         204 (xCC)            1251
     * EE_CHARSET              238 (xEE)            1250
     * GREEK_CHARSET           161 (xA1)            1253
     * TURKISH_CHARSET         162 (xA2)            1254
     * BALTIC_CHARSET          186 (xBA)            1257
     * HEBREW_CHARSET          177 (xB1)            1255
     * ARABIC _CHARSET         178 (xB2)            1256
     * SHIFTJIS_CHARSET        128 (x80)             932
     * HANGEUL_CHARSET         129 (x81)             949
     * GB2313_CHARSET          134 (x86)             936
     * CHINESEBIG5_CHARSET     136 (x88)             950
     * </pre>
     * 
     */
    virtual QCString trRTFansicp()
    {
      return "1252";
    }
    

    /*! Used as ansicpg for RTF fcharset 
     *  \see trRTFansicp() for a table of possible values.
     */
    virtual QCString trRTFCharSet()
    {
      return "0";
    }

    /*! Used as header RTF general index */
    virtual QCString trRTFGeneralIndex()
    {
      return "Index";
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trClass(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Class" : "class"));
      if (!singular)  result+="es";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trFile(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "File" : "file"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trNamespace(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Namespace" : "namespace"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGroup(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Group" : "group"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trPage(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Page" : "page"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trMember(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Member" : "member"));
      if (!singular)  result+="s";
      return result; 
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGlobal(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Global" : "global"));
      if (!singular)  result+="s";
      return result; 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.7
//////////////////////////////////////////////////////////////////////////

    /*! This text is generated when the \\author command is used and
     *  for the author section in man pages. */
    virtual QCString trAuthor(bool first_capital, bool singular)
    {                                                                         
      QCString result((first_capital ? "Author" : "author"));
      if (!singular)  result+="s";
      return result; 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.11
//////////////////////////////////////////////////////////////////////////

    /*! This text is put before the list of members referenced by a member
     */
    virtual QCString trReferences()
    {
      return "References";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.13
//////////////////////////////////////////////////////////////////////////

    /*! used in member documentation blocks to produce a list of 
     *  members that are implemented by this one.
     */
    virtual QCString trImplementedFromList(int numEntries)
    {
      return "Implements "+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of
     *  all members that implement this abstract member.
     */
    virtual QCString trImplementedInList(int numEntries)
    {
      return "Implemented in "+trWriteList(numEntries)+".";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.16
//////////////////////////////////////////////////////////////////////////

    /*! used in RTF documentation as a heading for the Table
     *  of Contents.
     */
    virtual QCString trRTFTableOfContents()
    {
      return "Table of Contents";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.17
//////////////////////////////////////////////////////////////////////////

    /*! Used as the header of the list of item that have been 
     *  flagged deprecated 
     */
    virtual QCString trDeprecatedList()
    {
      return "Deprecated List";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.18
//////////////////////////////////////////////////////////////////////////

    /*! Used as a header for declaration section of the events found in 
     * a C# program
     */
    virtual QCString trEvents()
    {
      return "Events";
    }
    /*! Header used for the documentation section of a class' events. */
    virtual QCString trEventDocumentation()
    {
      return "Event Documentation";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3
//////////////////////////////////////////////////////////////////////////

    /*! Used as a heading for a list of Java class types with package scope.
     */
    virtual QCString trPackageTypes()
    { 
      return "Package Types";
    }
    /*! Used as a heading for a list of Java class functions with package 
     * scope. 
     */
    virtual QCString trPackageMembers()
    { 
      return "Package Functions";
    }
    /*! Used as a heading for a list of static Java class functions with 
     *  package scope.
     */
    virtual QCString trStaticPackageMembers()
    { 
      return "Static Package Functions";
    }
    /*! Used as a heading for a list of Java class variables with package 
     * scope.
     */
    virtual QCString trPackageAttribs()
    { 
      return "Package Attributes";
    }
    /*! Used as a heading for a list of static Java class variables with 
     * package scope.
     */
    virtual QCString trStaticPackageAttribs()
    { 
      return "Static Package Attributes";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.3.1
//////////////////////////////////////////////////////////////////////////

    /*! Used in the quick index of a class/file/namespace member list page 
     *  to link to the unfiltered list of all members.
     */
    virtual QCString trAll()
    {
      return "All";
    }
    /*! Put in front of the call graph for a function. */
    virtual QCString trCallGraph()
    {
      return "Here is the call graph for this function:";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3.3
//////////////////////////////////////////////////////////////////////////

    /*! When the search engine is enabled this text is put in the header 
     *  of each page before the field where one can enter the text to search 
     *  for. 
     */
    virtual QCString trSearchForIndex()
    {
      return "Search for";
    }
    /*! This string is used as the title for the page listing the search
     *  results.
     */
    virtual QCString trSearchResultsTitle()
    {
      return "Search Results";
    }
    /*! This string is put just before listing the search results. The
     *  text can be different depending on the number of documents found.
     *  Inside the text you can put the special marker $num to insert
     *  the number representing the actual number of search results.
     *  The @a numDocuments parameter can be either 0, 1 or 2, where the 
     *  value 2 represents 2 or more matches. HTML markup is allowed inside
     *  the returned string.
     */
    virtual QCString trSearchResults(int numDocuments)
    {
      if (numDocuments==0)
      {
        return "Sorry, no documents matching your query.";
      }
      else if (numDocuments==1)
      {
        return "Found <b>1</b> document matching your query.";
      }
      else 
      {
        return "Found <b>$num</b> documents matching your query. "
               "Showing best matches first.";
      }
    }
    /*! This string is put before the list of matched words, for each search 
     *  result. What follows is the list of words that matched the query.
     */
    virtual QCString trSearchMatches()
    {
      return "Matches:";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3.8
//////////////////////////////////////////////////////////////////////////

    /*! This is used in HTML as the title of page with source code for file filename
     */
    virtual QCString trSourceFile(QCString& filename)
    {
      return filename + " Source File";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3.9
//////////////////////////////////////////////////////////////////////////

    /*! This is used as the name of the chapter containing the directory
     *  hierarchy.
     */
    virtual QCString trDirIndex()
    { return "Directory Hierarchy"; }

    /*! This is used as the name of the chapter containing the documentation
     *  of the directories.
     */
    virtual QCString trDirDocumentation()
    { return "Directory Documentation"; }

    /*! This is used as the title of the directory index and also in the
     *  Quick links of an HTML page, to link to the directory hierarchy.
     */
    virtual QCString trDirectories()
    { return "Directories"; }

    /*! This returns a sentences that introduces the directory hierarchy. 
     *  and the fact that it is sorted alphabetically per level
     */
    virtual QCString trDirDescription()
    { return "This directory hierarchy is sorted roughly, "
             "but not completely, alphabetically:";
    }

    /*! This returns the title of a directory page. The name of the
     *  directory is passed via \a dirName.
     */
    virtual QCString trDirReference(const char *dirName)
    { QCString result=dirName; result+=" Directory Reference"; return result; }

    /*! This returns the word directory with or without starting capital
     *  (\a first_capital) and in sigular or plural form (\a singular).
     */
    virtual QCString trDir(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Director" : "director"));
      if (singular) result+="y"; else result+="ies";
      return result; 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.4.1
//////////////////////////////////////////////////////////////////////////

    /*! This text is added to the documentation when the \\overload command
     *  is used for a overloaded function.
     */
    virtual QCString trOverloadText()
    {
       return "This is an overloaded member function, "
              "provided for convenience. It differs from the above "
              "function only in what argument(s) it accepts.";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.4.6
//////////////////////////////////////////////////////////////////////////

    /*! This is used to introduce a caller (or called-by) graph */
    virtual QCString trCallerGraph()
    {
      return "Here is the caller graph for this function:";
    }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration values
     */
    virtual QCString trEnumerationValueDocumentation()
    { return "Enumerator Documentation"; }

//////////////////////////////////////////////////////////////////////////
// new since 1.5.4 (mainly for Fortran)
//////////////////////////////////////////////////////////////////////////
    
    /*! header that is put before the list of member subprograms (Fortran). */
    virtual QCString trMemberFunctionDocumentationFortran()
    { return "Member Function/Subroutine Documentation"; }

    /*! This is put above each page as a link to the list of annotated data types (Fortran). */    
    virtual QCString trCompoundListFortran()
    { return "Data Types List"; }

    /*! This is put above each page as a link to all members of compounds (Fortran). */
    virtual QCString trCompoundMembersFortran()
    { return "Data Fields"; }

    /*! This is an introduction to the annotated compound list (Fortran). */
    virtual QCString trCompoundListDescriptionFortran()
    { return "Here are the data types with brief descriptions:"; }

    /*! This is an introduction to the page with all data types (Fortran). */
    virtual QCString trCompoundMembersDescriptionFortran(bool extractAll)
    {
      QCString result="Here is a list of all ";
      if (!extractAll)
      {
        result+="documented ";
      }
      result+="data types members";
      result+=" with links to ";
      if (!extractAll) 
      {
         result+="the data structure documentation for each member";
      }
      else 
      {
         result+="the data types they belong to:";
      }
      return result;
    }

    /*! This is used in LaTeX as the title of the chapter with the 
     * annotated compound index (Fortran).
     */
    virtual QCString trCompoundIndexFortran()
    { return "Data Type Index"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all data types (Fortran).
     */
    virtual QCString trTypeDocumentation()
    { return "Data Type Documentation"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) subprograms (Fortran).
     */
    virtual QCString trSubprograms()
    { return "Functions/Subroutines"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for subprograms (Fortran)
     */
    virtual QCString trSubprogramDocumentation()
    { return "Function/Subroutine Documentation"; }

    /*! This is used in the documentation of a file/namespace/group before 
     *  the list of links to documented compounds (Fortran)
     */
     virtual QCString trDataTypes()
    { return "Data Types"; }
    
    /*! used as the title of page containing all the index of all modules (Fortran). */
    virtual QCString trModulesList()
    { return "Modules List"; }

    /*! used as an introduction to the modules list (Fortran) */
    virtual QCString trModulesListDescription(bool extractAll)
    {
      QCString result="Here is a list of all ";
      if (!extractAll) result+="documented ";
      result+="modules with brief descriptions:";
      return result;
    }

    /*! used as the title of the HTML page of a module/type (Fortran) */
    virtual QCString trCompoundReferenceFortran(const char *clName,
                                    ClassDef::CompoundType compType,
                                    bool isTemplate)
    {
      QCString result=(QCString)clName;
      switch(compType)
      {
        case ClassDef::Class:      result+=" Module"; break;
        case ClassDef::Struct:     result+=" Type"; break;
        case ClassDef::Union:      result+=" Union"; break;
        case ClassDef::Interface:  result+=" Interface"; break;
        case ClassDef::Protocol:   result+=" Protocol"; break;
        case ClassDef::Category:   result+=" Category"; break;
        case ClassDef::Exception:  result+=" Exception"; break;
      }
      if (isTemplate) result+=" Template";
      result+=" Reference";
      return result;
    }
    /*! used as the title of the HTML page of a module (Fortran) */
    virtual QCString trModuleReference(const char *namespaceName)
    {
      QCString result=namespaceName;
      result+=" Module Reference";        
      return result;
    }
    
    /*! This is put above each page as a link to all members of modules. (Fortran) */
    virtual QCString trModulesMembers()
    { return "Module Members"; }

    /*! This is an introduction to the page with all modules members (Fortran) */
    virtual QCString trModulesMemberDescription(bool extractAll)
    { 
      QCString result="Here is a list of all ";
      if (!extractAll) result+="documented ";
      result+="module members with links to ";
      if (extractAll) 
      {
        result+="the module documentation for each member:";
      }
      else 
      {
        result+="the modules they belong to:";
      }
      return result;
    }

    /*! This is used in LaTeX as the title of the chapter with the 
     *  index of all modules (Fortran).
     */
    virtual QCString trModulesIndex()
    { return "Modules Index"; }
    
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trModule(bool first_capital, bool singular)
    {       
      QCString result((first_capital ? "Module" : "module"));
      if (!singular)  result+="s";
      return result; 
    }
    /*! This is put at the bottom of a module documentation page and is
     *  followed by a list of files that were used to generate the page.
     */
    virtual QCString trGeneratedFromFilesFortran(ClassDef::CompoundType compType,
        bool single)
    { // here s is one of " Module", " Struct" or " Union"
      // single is true implies a single file
      QCString result=(QCString)"The documentation for this ";
      switch(compType)
      {
        case ClassDef::Class:      result+="module"; break;
        case ClassDef::Struct:     result+="type"; break;
        case ClassDef::Union:      result+="union"; break;
        case ClassDef::Interface:  result+="interface"; break;
        case ClassDef::Protocol:   result+="protocol"; break;
        case ClassDef::Category:   result+="category"; break;
        case ClassDef::Exception:  result+="exception"; break;
      }
      result+=" was generated from the following file";
      if (single) result+=":"; else result+="s:";
      return result;
    }
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trType(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Type" : "type"));
      if (!singular)  result+="s";
      return result; 
    }
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trSubprogram(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Subprogram" : "subprogram"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! C# Type Constraint list */
    virtual QCString trTypeConstraints()
    {
      return "Type Constraints";
    }

};

#endif
