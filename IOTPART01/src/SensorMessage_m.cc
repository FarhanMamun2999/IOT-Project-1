//
// Generated file, do not edit! Created by opp_msgtool 6.0 from SensorMessage.msg.
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
#include <memory>
#include <type_traits>
#include "SensorMessage_m.h"

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
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
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

Register_Class(SensorMessage)

SensorMessage::SensorMessage(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

SensorMessage::SensorMessage(const SensorMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SensorMessage::~SensorMessage()
{
}

SensorMessage& SensorMessage::operator=(const SensorMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SensorMessage::copy(const SensorMessage& other)
{
    this->SensorName = other.SensorName;
    this->sensedTime = other.sensedTime;
    this->airHumidityValue = other.airHumidityValue;
    this->airTemperatureValue = other.airTemperatureValue;
    this->soilDampnessValue = other.soilDampnessValue;
    this->soilTemperatureValue = other.soilTemperatureValue;
    this->currentEnergyLevel = other.currentEnergyLevel;
}

void SensorMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->SensorName);
    doParsimPacking(b,this->sensedTime);
    doParsimPacking(b,this->airHumidityValue);
    doParsimPacking(b,this->airTemperatureValue);
    doParsimPacking(b,this->soilDampnessValue);
    doParsimPacking(b,this->soilTemperatureValue);
    doParsimPacking(b,this->currentEnergyLevel);
}

void SensorMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->SensorName);
    doParsimUnpacking(b,this->sensedTime);
    doParsimUnpacking(b,this->airHumidityValue);
    doParsimUnpacking(b,this->airTemperatureValue);
    doParsimUnpacking(b,this->soilDampnessValue);
    doParsimUnpacking(b,this->soilTemperatureValue);
    doParsimUnpacking(b,this->currentEnergyLevel);
}

const char * SensorMessage::getSensorName() const
{
    return this->SensorName.c_str();
}

void SensorMessage::setSensorName(const char * SensorName)
{
    this->SensorName = SensorName;
}

double SensorMessage::getSensedTime() const
{
    return this->sensedTime;
}

void SensorMessage::setSensedTime(double sensedTime)
{
    this->sensedTime = sensedTime;
}

double SensorMessage::getAirHumidityValue() const
{
    return this->airHumidityValue;
}

void SensorMessage::setAirHumidityValue(double airHumidityValue)
{
    this->airHumidityValue = airHumidityValue;
}

double SensorMessage::getAirTemperatureValue() const
{
    return this->airTemperatureValue;
}

void SensorMessage::setAirTemperatureValue(double airTemperatureValue)
{
    this->airTemperatureValue = airTemperatureValue;
}

double SensorMessage::getSoilDampnessValue() const
{
    return this->soilDampnessValue;
}

void SensorMessage::setSoilDampnessValue(double soilDampnessValue)
{
    this->soilDampnessValue = soilDampnessValue;
}

double SensorMessage::getSoilTemperatureValue() const
{
    return this->soilTemperatureValue;
}

void SensorMessage::setSoilTemperatureValue(double soilTemperatureValue)
{
    this->soilTemperatureValue = soilTemperatureValue;
}

double SensorMessage::getCurrentEnergyLevel() const
{
    return this->currentEnergyLevel;
}

void SensorMessage::setCurrentEnergyLevel(double currentEnergyLevel)
{
    this->currentEnergyLevel = currentEnergyLevel;
}

class SensorMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_SensorName,
        FIELD_sensedTime,
        FIELD_airHumidityValue,
        FIELD_airTemperatureValue,
        FIELD_soilDampnessValue,
        FIELD_soilTemperatureValue,
        FIELD_currentEnergyLevel,
    };
  public:
    SensorMessageDescriptor();
    virtual ~SensorMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SensorMessageDescriptor)

SensorMessageDescriptor::SensorMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(SensorMessage)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

SensorMessageDescriptor::~SensorMessageDescriptor()
{
    delete[] propertyNames;
}

bool SensorMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SensorMessage *>(obj)!=nullptr;
}

const char **SensorMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SensorMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SensorMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int SensorMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SensorName
        FD_ISEDITABLE,    // FIELD_sensedTime
        FD_ISEDITABLE,    // FIELD_airHumidityValue
        FD_ISEDITABLE,    // FIELD_airTemperatureValue
        FD_ISEDITABLE,    // FIELD_soilDampnessValue
        FD_ISEDITABLE,    // FIELD_soilTemperatureValue
        FD_ISEDITABLE,    // FIELD_currentEnergyLevel
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *SensorMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SensorName",
        "sensedTime",
        "airHumidityValue",
        "airTemperatureValue",
        "soilDampnessValue",
        "soilTemperatureValue",
        "currentEnergyLevel",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int SensorMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "SensorName") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sensedTime") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "airHumidityValue") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "airTemperatureValue") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "soilDampnessValue") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "soilTemperatureValue") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "currentEnergyLevel") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *SensorMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_SensorName
        "double",    // FIELD_sensedTime
        "double",    // FIELD_airHumidityValue
        "double",    // FIELD_airTemperatureValue
        "double",    // FIELD_soilDampnessValue
        "double",    // FIELD_soilTemperatureValue
        "double",    // FIELD_currentEnergyLevel
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **SensorMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SensorMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SensorMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SensorMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SensorMessage'", field);
    }
}

const char *SensorMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SensorMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_SensorName: return oppstring2string(pp->getSensorName());
        case FIELD_sensedTime: return double2string(pp->getSensedTime());
        case FIELD_airHumidityValue: return double2string(pp->getAirHumidityValue());
        case FIELD_airTemperatureValue: return double2string(pp->getAirTemperatureValue());
        case FIELD_soilDampnessValue: return double2string(pp->getSoilDampnessValue());
        case FIELD_soilTemperatureValue: return double2string(pp->getSoilTemperatureValue());
        case FIELD_currentEnergyLevel: return double2string(pp->getCurrentEnergyLevel());
        default: return "";
    }
}

void SensorMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_SensorName: pp->setSensorName((value)); break;
        case FIELD_sensedTime: pp->setSensedTime(string2double(value)); break;
        case FIELD_airHumidityValue: pp->setAirHumidityValue(string2double(value)); break;
        case FIELD_airTemperatureValue: pp->setAirTemperatureValue(string2double(value)); break;
        case FIELD_soilDampnessValue: pp->setSoilDampnessValue(string2double(value)); break;
        case FIELD_soilTemperatureValue: pp->setSoilTemperatureValue(string2double(value)); break;
        case FIELD_currentEnergyLevel: pp->setCurrentEnergyLevel(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SensorMessage'", field);
    }
}

omnetpp::cValue SensorMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_SensorName: return pp->getSensorName();
        case FIELD_sensedTime: return pp->getSensedTime();
        case FIELD_airHumidityValue: return pp->getAirHumidityValue();
        case FIELD_airTemperatureValue: return pp->getAirTemperatureValue();
        case FIELD_soilDampnessValue: return pp->getSoilDampnessValue();
        case FIELD_soilTemperatureValue: return pp->getSoilTemperatureValue();
        case FIELD_currentEnergyLevel: return pp->getCurrentEnergyLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'SensorMessage' as cValue -- field index out of range?", field);
    }
}

void SensorMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_SensorName: pp->setSensorName(value.stringValue()); break;
        case FIELD_sensedTime: pp->setSensedTime(value.doubleValue()); break;
        case FIELD_airHumidityValue: pp->setAirHumidityValue(value.doubleValue()); break;
        case FIELD_airTemperatureValue: pp->setAirTemperatureValue(value.doubleValue()); break;
        case FIELD_soilDampnessValue: pp->setSoilDampnessValue(value.doubleValue()); break;
        case FIELD_soilTemperatureValue: pp->setSoilTemperatureValue(value.doubleValue()); break;
        case FIELD_currentEnergyLevel: pp->setCurrentEnergyLevel(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SensorMessage'", field);
    }
}

const char *SensorMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr SensorMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SensorMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    SensorMessage *pp = omnetpp::fromAnyPtr<SensorMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SensorMessage'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

