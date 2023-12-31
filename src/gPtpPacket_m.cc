//
// Generated file, do not edit! Created by nedtool 5.2 from gPtpPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "gPtpPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(gPtp_Sync)

gPtp_Sync::gPtp_Sync(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
}

gPtp_Sync::gPtp_Sync(const gPtp_Sync& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

gPtp_Sync::~gPtp_Sync()
{
}

gPtp_Sync& gPtp_Sync::operator=(const gPtp_Sync& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void gPtp_Sync::copy(const gPtp_Sync& other)
{
    this->sentTime = other.sentTime;
    this->originTimestamp = other.originTimestamp;
}

void gPtp_Sync::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sentTime);
    doParsimPacking(b,this->originTimestamp);
}

void gPtp_Sync::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sentTime);
    doParsimUnpacking(b,this->originTimestamp);
}

omnetpp::SimTime& gPtp_Sync::getSentTime()
{
    return this->sentTime;
}

void gPtp_Sync::setSentTime(const omnetpp::SimTime& sentTime)
{
    this->sentTime = sentTime;
}

omnetpp::SimTime& gPtp_Sync::getOriginTimestamp()
{
    return this->originTimestamp;
}

void gPtp_Sync::setOriginTimestamp(const omnetpp::SimTime& originTimestamp)
{
    this->originTimestamp = originTimestamp;
}

class gPtp_SyncDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    gPtp_SyncDescriptor();
    virtual ~gPtp_SyncDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(gPtp_SyncDescriptor)

gPtp_SyncDescriptor::gPtp_SyncDescriptor() : omnetpp::cClassDescriptor("gPtp_Sync", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

gPtp_SyncDescriptor::~gPtp_SyncDescriptor()
{
    delete[] propertynames;
}

bool gPtp_SyncDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<gPtp_Sync *>(obj)!=nullptr;
}

const char **gPtp_SyncDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *gPtp_SyncDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int gPtp_SyncDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int gPtp_SyncDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *gPtp_SyncDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sentTime",
        "originTimestamp",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int gPtp_SyncDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sentTime")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "originTimestamp")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *gPtp_SyncDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::SimTime",
        "omnetpp::SimTime",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **gPtp_SyncDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *gPtp_SyncDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int gPtp_SyncDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    gPtp_Sync *pp = (gPtp_Sync *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *gPtp_SyncDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_Sync *pp = (gPtp_Sync *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string gPtp_SyncDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_Sync *pp = (gPtp_Sync *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSentTime(); return out.str();}
        case 1: {std::stringstream out; out << pp->getOriginTimestamp(); return out.str();}
        default: return "";
    }
}

bool gPtp_SyncDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    gPtp_Sync *pp = (gPtp_Sync *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *gPtp_SyncDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 1: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        default: return nullptr;
    };
}

void *gPtp_SyncDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    gPtp_Sync *pp = (gPtp_Sync *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSentTime()); break;
        case 1: return (void *)(&pp->getOriginTimestamp()); break;
        default: return nullptr;
    }
}

Register_Class(gPtp_FollowUp)

gPtp_FollowUp::gPtp_FollowUp(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->rateRatio = 0;
    this->numberOfHops = 0;
}

gPtp_FollowUp::gPtp_FollowUp(const gPtp_FollowUp& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

gPtp_FollowUp::~gPtp_FollowUp()
{
}

gPtp_FollowUp& gPtp_FollowUp::operator=(const gPtp_FollowUp& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void gPtp_FollowUp::copy(const gPtp_FollowUp& other)
{
    this->sentTime = other.sentTime;
    this->preciseOriginTimestamp = other.preciseOriginTimestamp;
    this->correctionField = other.correctionField;
    this->neighborRateRatio = other.neighborRateRatio;
    this->rateRatio = other.rateRatio;
    this->numberOfHops = other.numberOfHops;
}

void gPtp_FollowUp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sentTime);
    doParsimPacking(b,this->preciseOriginTimestamp);
    doParsimPacking(b,this->correctionField);
    doParsimPacking(b,this->neighborRateRatio);
    doParsimPacking(b,this->rateRatio);
    doParsimPacking(b,this->numberOfHops);
}

void gPtp_FollowUp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sentTime);
    doParsimUnpacking(b,this->preciseOriginTimestamp);
    doParsimUnpacking(b,this->correctionField);
    doParsimUnpacking(b,this->neighborRateRatio);
    doParsimUnpacking(b,this->rateRatio);
    doParsimUnpacking(b,this->numberOfHops);
}

omnetpp::SimTime& gPtp_FollowUp::getSentTime()
{
    return this->sentTime;
}

void gPtp_FollowUp::setSentTime(const omnetpp::SimTime& sentTime)
{
    this->sentTime = sentTime;
}

omnetpp::SimTime& gPtp_FollowUp::getPreciseOriginTimestamp()
{
    return this->preciseOriginTimestamp;
}

void gPtp_FollowUp::setPreciseOriginTimestamp(const omnetpp::SimTime& preciseOriginTimestamp)
{
    this->preciseOriginTimestamp = preciseOriginTimestamp;
}

omnetpp::SimTime& gPtp_FollowUp::getCorrectionField()
{
    return this->correctionField;
}

void gPtp_FollowUp::setCorrectionField(const omnetpp::SimTime& correctionField)
{
    this->correctionField = correctionField;
}

omnetpp::SimTime& gPtp_FollowUp::getNeighborRateRatio()
{
    return this->neighborRateRatio;
}

void gPtp_FollowUp::setNeighborRateRatio(const omnetpp::SimTime& neighborRateRatio)
{
    this->neighborRateRatio = neighborRateRatio;
}

double gPtp_FollowUp::getRateRatio() const
{
    return this->rateRatio;
}

void gPtp_FollowUp::setRateRatio(double rateRatio)
{
    this->rateRatio = rateRatio;
}

int gPtp_FollowUp::getNumberOfHops() const
{
    return this->numberOfHops;
}

void gPtp_FollowUp::setNumberOfHops(int numberOfHops)
{
    this->numberOfHops = numberOfHops;
}

class gPtp_FollowUpDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    gPtp_FollowUpDescriptor();
    virtual ~gPtp_FollowUpDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(gPtp_FollowUpDescriptor)

gPtp_FollowUpDescriptor::gPtp_FollowUpDescriptor() : omnetpp::cClassDescriptor("gPtp_FollowUp", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

gPtp_FollowUpDescriptor::~gPtp_FollowUpDescriptor()
{
    delete[] propertynames;
}

bool gPtp_FollowUpDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<gPtp_FollowUp *>(obj)!=nullptr;
}

const char **gPtp_FollowUpDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *gPtp_FollowUpDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int gPtp_FollowUpDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int gPtp_FollowUpDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *gPtp_FollowUpDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sentTime",
        "preciseOriginTimestamp",
        "correctionField",
        "neighborRateRatio",
        "rateRatio",
        "numberOfHops",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int gPtp_FollowUpDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sentTime")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "preciseOriginTimestamp")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "correctionField")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborRateRatio")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "rateRatio")==0) return base+4;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfHops")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *gPtp_FollowUpDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::SimTime",
        "omnetpp::SimTime",
        "omnetpp::SimTime",
        "omnetpp::SimTime",
        "double",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **gPtp_FollowUpDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *gPtp_FollowUpDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int gPtp_FollowUpDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    gPtp_FollowUp *pp = (gPtp_FollowUp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *gPtp_FollowUpDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_FollowUp *pp = (gPtp_FollowUp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string gPtp_FollowUpDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_FollowUp *pp = (gPtp_FollowUp *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSentTime(); return out.str();}
        case 1: {std::stringstream out; out << pp->getPreciseOriginTimestamp(); return out.str();}
        case 2: {std::stringstream out; out << pp->getCorrectionField(); return out.str();}
        case 3: {std::stringstream out; out << pp->getNeighborRateRatio(); return out.str();}
        case 4: return double2string(pp->getRateRatio());
        case 5: return long2string(pp->getNumberOfHops());
        default: return "";
    }
}

bool gPtp_FollowUpDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    gPtp_FollowUp *pp = (gPtp_FollowUp *)object; (void)pp;
    switch (field) {
        case 4: pp->setRateRatio(string2double(value)); return true;
        case 5: pp->setNumberOfHops(string2long(value)); return true;
        default: return false;
    }
}

const char *gPtp_FollowUpDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 1: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 2: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 3: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        default: return nullptr;
    };
}

void *gPtp_FollowUpDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    gPtp_FollowUp *pp = (gPtp_FollowUp *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSentTime()); break;
        case 1: return (void *)(&pp->getPreciseOriginTimestamp()); break;
        case 2: return (void *)(&pp->getCorrectionField()); break;
        case 3: return (void *)(&pp->getNeighborRateRatio()); break;
        default: return nullptr;
    }
}

Register_Class(gPtp_PdelayReq)

gPtp_PdelayReq::gPtp_PdelayReq(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->requestingPortIdentity = 0;
}

gPtp_PdelayReq::gPtp_PdelayReq(const gPtp_PdelayReq& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

gPtp_PdelayReq::~gPtp_PdelayReq()
{
}

gPtp_PdelayReq& gPtp_PdelayReq::operator=(const gPtp_PdelayReq& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void gPtp_PdelayReq::copy(const gPtp_PdelayReq& other)
{
    this->sentTime = other.sentTime;
    this->originTimestamp = other.originTimestamp;
    this->requestingPortIdentity = other.requestingPortIdentity;
}

void gPtp_PdelayReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sentTime);
    doParsimPacking(b,this->originTimestamp);
    doParsimPacking(b,this->requestingPortIdentity);
}

void gPtp_PdelayReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sentTime);
    doParsimUnpacking(b,this->originTimestamp);
    doParsimUnpacking(b,this->requestingPortIdentity);
}

omnetpp::SimTime& gPtp_PdelayReq::getSentTime()
{
    return this->sentTime;
}

void gPtp_PdelayReq::setSentTime(const omnetpp::SimTime& sentTime)
{
    this->sentTime = sentTime;
}

omnetpp::SimTime& gPtp_PdelayReq::getOriginTimestamp()
{
    return this->originTimestamp;
}

void gPtp_PdelayReq::setOriginTimestamp(const omnetpp::SimTime& originTimestamp)
{
    this->originTimestamp = originTimestamp;
}

int gPtp_PdelayReq::getRequestingPortIdentity() const
{
    return this->requestingPortIdentity;
}

void gPtp_PdelayReq::setRequestingPortIdentity(int requestingPortIdentity)
{
    this->requestingPortIdentity = requestingPortIdentity;
}

class gPtp_PdelayReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    gPtp_PdelayReqDescriptor();
    virtual ~gPtp_PdelayReqDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(gPtp_PdelayReqDescriptor)

gPtp_PdelayReqDescriptor::gPtp_PdelayReqDescriptor() : omnetpp::cClassDescriptor("gPtp_PdelayReq", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

gPtp_PdelayReqDescriptor::~gPtp_PdelayReqDescriptor()
{
    delete[] propertynames;
}

bool gPtp_PdelayReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<gPtp_PdelayReq *>(obj)!=nullptr;
}

const char **gPtp_PdelayReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *gPtp_PdelayReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int gPtp_PdelayReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int gPtp_PdelayReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *gPtp_PdelayReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sentTime",
        "originTimestamp",
        "requestingPortIdentity",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int gPtp_PdelayReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sentTime")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "originTimestamp")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestingPortIdentity")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *gPtp_PdelayReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::SimTime",
        "omnetpp::SimTime",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **gPtp_PdelayReqDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *gPtp_PdelayReqDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int gPtp_PdelayReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayReq *pp = (gPtp_PdelayReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *gPtp_PdelayReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayReq *pp = (gPtp_PdelayReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string gPtp_PdelayReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayReq *pp = (gPtp_PdelayReq *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSentTime(); return out.str();}
        case 1: {std::stringstream out; out << pp->getOriginTimestamp(); return out.str();}
        case 2: return long2string(pp->getRequestingPortIdentity());
        default: return "";
    }
}

bool gPtp_PdelayReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayReq *pp = (gPtp_PdelayReq *)object; (void)pp;
    switch (field) {
        case 2: pp->setRequestingPortIdentity(string2long(value)); return true;
        default: return false;
    }
}

const char *gPtp_PdelayReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 1: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        default: return nullptr;
    };
}

void *gPtp_PdelayReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayReq *pp = (gPtp_PdelayReq *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSentTime()); break;
        case 1: return (void *)(&pp->getOriginTimestamp()); break;
        default: return nullptr;
    }
}

Register_Class(gPtp_PdelayResp)

gPtp_PdelayResp::gPtp_PdelayResp(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->requestingPortIdentity = 0;
}

gPtp_PdelayResp::gPtp_PdelayResp(const gPtp_PdelayResp& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

gPtp_PdelayResp::~gPtp_PdelayResp()
{
}

gPtp_PdelayResp& gPtp_PdelayResp::operator=(const gPtp_PdelayResp& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void gPtp_PdelayResp::copy(const gPtp_PdelayResp& other)
{
    this->sentTime = other.sentTime;
    this->requestReceiptTimestamp = other.requestReceiptTimestamp;
    this->requestingPortIdentity = other.requestingPortIdentity;
}

void gPtp_PdelayResp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sentTime);
    doParsimPacking(b,this->requestReceiptTimestamp);
    doParsimPacking(b,this->requestingPortIdentity);
}

void gPtp_PdelayResp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sentTime);
    doParsimUnpacking(b,this->requestReceiptTimestamp);
    doParsimUnpacking(b,this->requestingPortIdentity);
}

omnetpp::SimTime& gPtp_PdelayResp::getSentTime()
{
    return this->sentTime;
}

void gPtp_PdelayResp::setSentTime(const omnetpp::SimTime& sentTime)
{
    this->sentTime = sentTime;
}

omnetpp::SimTime& gPtp_PdelayResp::getRequestReceiptTimestamp()
{
    return this->requestReceiptTimestamp;
}

void gPtp_PdelayResp::setRequestReceiptTimestamp(const omnetpp::SimTime& requestReceiptTimestamp)
{
    this->requestReceiptTimestamp = requestReceiptTimestamp;
}

int gPtp_PdelayResp::getRequestingPortIdentity() const
{
    return this->requestingPortIdentity;
}

void gPtp_PdelayResp::setRequestingPortIdentity(int requestingPortIdentity)
{
    this->requestingPortIdentity = requestingPortIdentity;
}

class gPtp_PdelayRespDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    gPtp_PdelayRespDescriptor();
    virtual ~gPtp_PdelayRespDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(gPtp_PdelayRespDescriptor)

gPtp_PdelayRespDescriptor::gPtp_PdelayRespDescriptor() : omnetpp::cClassDescriptor("gPtp_PdelayResp", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

gPtp_PdelayRespDescriptor::~gPtp_PdelayRespDescriptor()
{
    delete[] propertynames;
}

bool gPtp_PdelayRespDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<gPtp_PdelayResp *>(obj)!=nullptr;
}

const char **gPtp_PdelayRespDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *gPtp_PdelayRespDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int gPtp_PdelayRespDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int gPtp_PdelayRespDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *gPtp_PdelayRespDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sentTime",
        "requestReceiptTimestamp",
        "requestingPortIdentity",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int gPtp_PdelayRespDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sentTime")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestReceiptTimestamp")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestingPortIdentity")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *gPtp_PdelayRespDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::SimTime",
        "omnetpp::SimTime",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **gPtp_PdelayRespDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *gPtp_PdelayRespDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int gPtp_PdelayRespDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayResp *pp = (gPtp_PdelayResp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *gPtp_PdelayRespDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayResp *pp = (gPtp_PdelayResp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string gPtp_PdelayRespDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayResp *pp = (gPtp_PdelayResp *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSentTime(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRequestReceiptTimestamp(); return out.str();}
        case 2: return long2string(pp->getRequestingPortIdentity());
        default: return "";
    }
}

bool gPtp_PdelayRespDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayResp *pp = (gPtp_PdelayResp *)object; (void)pp;
    switch (field) {
        case 2: pp->setRequestingPortIdentity(string2long(value)); return true;
        default: return false;
    }
}

const char *gPtp_PdelayRespDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 1: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        default: return nullptr;
    };
}

void *gPtp_PdelayRespDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayResp *pp = (gPtp_PdelayResp *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSentTime()); break;
        case 1: return (void *)(&pp->getRequestReceiptTimestamp()); break;
        default: return nullptr;
    }
}

Register_Class(gPtp_PdelayRespFollowUp)

gPtp_PdelayRespFollowUp::gPtp_PdelayRespFollowUp(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->requestingPortIdentity = 0;
}

gPtp_PdelayRespFollowUp::gPtp_PdelayRespFollowUp(const gPtp_PdelayRespFollowUp& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

gPtp_PdelayRespFollowUp::~gPtp_PdelayRespFollowUp()
{
}

gPtp_PdelayRespFollowUp& gPtp_PdelayRespFollowUp::operator=(const gPtp_PdelayRespFollowUp& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void gPtp_PdelayRespFollowUp::copy(const gPtp_PdelayRespFollowUp& other)
{
    this->sentTime = other.sentTime;
    this->responseOriginTimestamp = other.responseOriginTimestamp;
    this->requestingPortIdentity = other.requestingPortIdentity;
}

void gPtp_PdelayRespFollowUp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sentTime);
    doParsimPacking(b,this->responseOriginTimestamp);
    doParsimPacking(b,this->requestingPortIdentity);
}

void gPtp_PdelayRespFollowUp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sentTime);
    doParsimUnpacking(b,this->responseOriginTimestamp);
    doParsimUnpacking(b,this->requestingPortIdentity);
}

omnetpp::SimTime& gPtp_PdelayRespFollowUp::getSentTime()
{
    return this->sentTime;
}

void gPtp_PdelayRespFollowUp::setSentTime(const omnetpp::SimTime& sentTime)
{
    this->sentTime = sentTime;
}

omnetpp::SimTime& gPtp_PdelayRespFollowUp::getResponseOriginTimestamp()
{
    return this->responseOriginTimestamp;
}

void gPtp_PdelayRespFollowUp::setResponseOriginTimestamp(const omnetpp::SimTime& responseOriginTimestamp)
{
    this->responseOriginTimestamp = responseOriginTimestamp;
}

int gPtp_PdelayRespFollowUp::getRequestingPortIdentity() const
{
    return this->requestingPortIdentity;
}

void gPtp_PdelayRespFollowUp::setRequestingPortIdentity(int requestingPortIdentity)
{
    this->requestingPortIdentity = requestingPortIdentity;
}

class gPtp_PdelayRespFollowUpDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    gPtp_PdelayRespFollowUpDescriptor();
    virtual ~gPtp_PdelayRespFollowUpDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(gPtp_PdelayRespFollowUpDescriptor)

gPtp_PdelayRespFollowUpDescriptor::gPtp_PdelayRespFollowUpDescriptor() : omnetpp::cClassDescriptor("gPtp_PdelayRespFollowUp", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

gPtp_PdelayRespFollowUpDescriptor::~gPtp_PdelayRespFollowUpDescriptor()
{
    delete[] propertynames;
}

bool gPtp_PdelayRespFollowUpDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<gPtp_PdelayRespFollowUp *>(obj)!=nullptr;
}

const char **gPtp_PdelayRespFollowUpDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *gPtp_PdelayRespFollowUpDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int gPtp_PdelayRespFollowUpDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int gPtp_PdelayRespFollowUpDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *gPtp_PdelayRespFollowUpDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sentTime",
        "responseOriginTimestamp",
        "requestingPortIdentity",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int gPtp_PdelayRespFollowUpDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sentTime")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "responseOriginTimestamp")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestingPortIdentity")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *gPtp_PdelayRespFollowUpDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::SimTime",
        "omnetpp::SimTime",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **gPtp_PdelayRespFollowUpDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *gPtp_PdelayRespFollowUpDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int gPtp_PdelayRespFollowUpDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayRespFollowUp *pp = (gPtp_PdelayRespFollowUp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *gPtp_PdelayRespFollowUpDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayRespFollowUp *pp = (gPtp_PdelayRespFollowUp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string gPtp_PdelayRespFollowUpDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayRespFollowUp *pp = (gPtp_PdelayRespFollowUp *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSentTime(); return out.str();}
        case 1: {std::stringstream out; out << pp->getResponseOriginTimestamp(); return out.str();}
        case 2: return long2string(pp->getRequestingPortIdentity());
        default: return "";
    }
}

bool gPtp_PdelayRespFollowUpDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayRespFollowUp *pp = (gPtp_PdelayRespFollowUp *)object; (void)pp;
    switch (field) {
        case 2: pp->setRequestingPortIdentity(string2long(value)); return true;
        default: return false;
    }
}

const char *gPtp_PdelayRespFollowUpDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        case 1: return omnetpp::opp_typename(typeid(omnetpp::SimTime));
        default: return nullptr;
    };
}

void *gPtp_PdelayRespFollowUpDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    gPtp_PdelayRespFollowUp *pp = (gPtp_PdelayRespFollowUp *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSentTime()); break;
        case 1: return (void *)(&pp->getResponseOriginTimestamp()); break;
        default: return nullptr;
    }
}


