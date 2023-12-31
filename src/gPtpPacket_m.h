//
// Generated file, do not edit! Created by nedtool 5.2 from gPtpPacket.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __GPTPPACKET_M_H
#define __GPTPPACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "omnetpp/simtime.h"
#include "gPtp.h"
#include "omnetpp.h"
// }}

/**
 * Class generated from <tt>gPtpPacket.msg:18</tt> by nedtool.
 * <pre>
 * packet gPtp_Sync
 * {
 *     omnetpp::SimTime sentTime;
 *     omnetpp::SimTime originTimestamp;
 * }
 * </pre>
 */
class gPtp_Sync : public ::omnetpp::cPacket
{
  protected:
    omnetpp::SimTime sentTime;
    omnetpp::SimTime originTimestamp;

  private:
    void copy(const gPtp_Sync& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const gPtp_Sync&);

  public:
    gPtp_Sync(const char *name=nullptr, short kind=0);
    gPtp_Sync(const gPtp_Sync& other);
    virtual ~gPtp_Sync();
    gPtp_Sync& operator=(const gPtp_Sync& other);
    virtual gPtp_Sync *dup() const override {return new gPtp_Sync(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual omnetpp::SimTime& getSentTime();
    virtual const omnetpp::SimTime& getSentTime() const {return const_cast<gPtp_Sync*>(this)->getSentTime();}
    virtual void setSentTime(const omnetpp::SimTime& sentTime);
    virtual omnetpp::SimTime& getOriginTimestamp();
    virtual const omnetpp::SimTime& getOriginTimestamp() const {return const_cast<gPtp_Sync*>(this)->getOriginTimestamp();}
    virtual void setOriginTimestamp(const omnetpp::SimTime& originTimestamp);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const gPtp_Sync& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, gPtp_Sync& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>gPtpPacket.msg:24</tt> by nedtool.
 * <pre>
 * packet gPtp_FollowUp
 * {
 *     omnetpp::SimTime sentTime;
 *     omnetpp::SimTime preciseOriginTimestamp;
 *     omnetpp::SimTime correctionField;
 *     omnetpp::SimTime neighborRateRatio;
 *     double rateRatio;
 *     int numberOfHops;
 * }
 * </pre>
 */
class gPtp_FollowUp : public ::omnetpp::cPacket
{
  protected:
    omnetpp::SimTime sentTime;
    omnetpp::SimTime preciseOriginTimestamp;
    omnetpp::SimTime correctionField;
    omnetpp::SimTime neighborRateRatio;
    double rateRatio;
    int numberOfHops;

  private:
    void copy(const gPtp_FollowUp& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const gPtp_FollowUp&);

  public:
    gPtp_FollowUp(const char *name=nullptr, short kind=0);
    gPtp_FollowUp(const gPtp_FollowUp& other);
    virtual ~gPtp_FollowUp();
    gPtp_FollowUp& operator=(const gPtp_FollowUp& other);
    virtual gPtp_FollowUp *dup() const override {return new gPtp_FollowUp(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual omnetpp::SimTime& getSentTime();
    virtual const omnetpp::SimTime& getSentTime() const {return const_cast<gPtp_FollowUp*>(this)->getSentTime();}
    virtual void setSentTime(const omnetpp::SimTime& sentTime);
    virtual omnetpp::SimTime& getPreciseOriginTimestamp();
    virtual const omnetpp::SimTime& getPreciseOriginTimestamp() const {return const_cast<gPtp_FollowUp*>(this)->getPreciseOriginTimestamp();}
    virtual void setPreciseOriginTimestamp(const omnetpp::SimTime& preciseOriginTimestamp);
    virtual omnetpp::SimTime& getCorrectionField();
    virtual const omnetpp::SimTime& getCorrectionField() const {return const_cast<gPtp_FollowUp*>(this)->getCorrectionField();}
    virtual void setCorrectionField(const omnetpp::SimTime& correctionField);
    virtual omnetpp::SimTime& getNeighborRateRatio();
    virtual const omnetpp::SimTime& getNeighborRateRatio() const {return const_cast<gPtp_FollowUp*>(this)->getNeighborRateRatio();}
    virtual void setNeighborRateRatio(const omnetpp::SimTime& neighborRateRatio);
    virtual double getRateRatio() const;
    virtual void setRateRatio(double rateRatio);
    virtual int getNumberOfHops() const;
    virtual void setNumberOfHops(int numberOfHops);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const gPtp_FollowUp& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, gPtp_FollowUp& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>gPtpPacket.msg:34</tt> by nedtool.
 * <pre>
 * packet gPtp_PdelayReq
 * {
 *     omnetpp::SimTime sentTime;
 *     omnetpp::SimTime originTimestamp;
 *     int requestingPortIdentity;
 * }
 * </pre>
 */
class gPtp_PdelayReq : public ::omnetpp::cPacket
{
  protected:
    omnetpp::SimTime sentTime;
    omnetpp::SimTime originTimestamp;
    int requestingPortIdentity;

  private:
    void copy(const gPtp_PdelayReq& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const gPtp_PdelayReq&);

  public:
    gPtp_PdelayReq(const char *name=nullptr, short kind=0);
    gPtp_PdelayReq(const gPtp_PdelayReq& other);
    virtual ~gPtp_PdelayReq();
    gPtp_PdelayReq& operator=(const gPtp_PdelayReq& other);
    virtual gPtp_PdelayReq *dup() const override {return new gPtp_PdelayReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual omnetpp::SimTime& getSentTime();
    virtual const omnetpp::SimTime& getSentTime() const {return const_cast<gPtp_PdelayReq*>(this)->getSentTime();}
    virtual void setSentTime(const omnetpp::SimTime& sentTime);
    virtual omnetpp::SimTime& getOriginTimestamp();
    virtual const omnetpp::SimTime& getOriginTimestamp() const {return const_cast<gPtp_PdelayReq*>(this)->getOriginTimestamp();}
    virtual void setOriginTimestamp(const omnetpp::SimTime& originTimestamp);
    virtual int getRequestingPortIdentity() const;
    virtual void setRequestingPortIdentity(int requestingPortIdentity);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const gPtp_PdelayReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, gPtp_PdelayReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>gPtpPacket.msg:41</tt> by nedtool.
 * <pre>
 * packet gPtp_PdelayResp
 * {
 *     omnetpp::SimTime sentTime;
 *     omnetpp::SimTime requestReceiptTimestamp;
 *     int requestingPortIdentity;
 * }
 * </pre>
 */
class gPtp_PdelayResp : public ::omnetpp::cPacket
{
  protected:
    omnetpp::SimTime sentTime;
    omnetpp::SimTime requestReceiptTimestamp;
    int requestingPortIdentity;

  private:
    void copy(const gPtp_PdelayResp& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const gPtp_PdelayResp&);

  public:
    gPtp_PdelayResp(const char *name=nullptr, short kind=0);
    gPtp_PdelayResp(const gPtp_PdelayResp& other);
    virtual ~gPtp_PdelayResp();
    gPtp_PdelayResp& operator=(const gPtp_PdelayResp& other);
    virtual gPtp_PdelayResp *dup() const override {return new gPtp_PdelayResp(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual omnetpp::SimTime& getSentTime();
    virtual const omnetpp::SimTime& getSentTime() const {return const_cast<gPtp_PdelayResp*>(this)->getSentTime();}
    virtual void setSentTime(const omnetpp::SimTime& sentTime);
    virtual omnetpp::SimTime& getRequestReceiptTimestamp();
    virtual const omnetpp::SimTime& getRequestReceiptTimestamp() const {return const_cast<gPtp_PdelayResp*>(this)->getRequestReceiptTimestamp();}
    virtual void setRequestReceiptTimestamp(const omnetpp::SimTime& requestReceiptTimestamp);
    virtual int getRequestingPortIdentity() const;
    virtual void setRequestingPortIdentity(int requestingPortIdentity);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const gPtp_PdelayResp& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, gPtp_PdelayResp& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>gPtpPacket.msg:48</tt> by nedtool.
 * <pre>
 * packet gPtp_PdelayRespFollowUp
 * {
 *     omnetpp::SimTime sentTime;
 *     omnetpp::SimTime responseOriginTimestamp;
 *     int requestingPortIdentity;
 * }
 * </pre>
 */
class gPtp_PdelayRespFollowUp : public ::omnetpp::cPacket
{
  protected:
    omnetpp::SimTime sentTime;
    omnetpp::SimTime responseOriginTimestamp;
    int requestingPortIdentity;

  private:
    void copy(const gPtp_PdelayRespFollowUp& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const gPtp_PdelayRespFollowUp&);

  public:
    gPtp_PdelayRespFollowUp(const char *name=nullptr, short kind=0);
    gPtp_PdelayRespFollowUp(const gPtp_PdelayRespFollowUp& other);
    virtual ~gPtp_PdelayRespFollowUp();
    gPtp_PdelayRespFollowUp& operator=(const gPtp_PdelayRespFollowUp& other);
    virtual gPtp_PdelayRespFollowUp *dup() const override {return new gPtp_PdelayRespFollowUp(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual omnetpp::SimTime& getSentTime();
    virtual const omnetpp::SimTime& getSentTime() const {return const_cast<gPtp_PdelayRespFollowUp*>(this)->getSentTime();}
    virtual void setSentTime(const omnetpp::SimTime& sentTime);
    virtual omnetpp::SimTime& getResponseOriginTimestamp();
    virtual const omnetpp::SimTime& getResponseOriginTimestamp() const {return const_cast<gPtp_PdelayRespFollowUp*>(this)->getResponseOriginTimestamp();}
    virtual void setResponseOriginTimestamp(const omnetpp::SimTime& responseOriginTimestamp);
    virtual int getRequestingPortIdentity() const;
    virtual void setRequestingPortIdentity(int requestingPortIdentity);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const gPtp_PdelayRespFollowUp& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, gPtp_PdelayRespFollowUp& obj) {obj.parsimUnpack(b);}


#endif // ifndef __GPTPPACKET_M_H

