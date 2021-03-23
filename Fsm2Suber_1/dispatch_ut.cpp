class C_DISPATH_UT
{
public:
    C_DISPATH_UT();
    C_DISPATH_UT(C_DISPATH_UT &&) = default;
    C_DISPATH_UT(const C_DISPATH_UT &) = default;
    C_DISPATH_UT &operator=(C_DISPATH_UT &&) = default;
    C_DISPATH_UT &operator=(const C_DISPATH_UT &) = default;
    ~C_DISPATH_UT();
    void callback_fun(S_DISPATCH_LISTEN_EVENT tmpCurrDispathUt);

private:
    int mCurrSchedId;
    S_EVENT_UT mNextEventUt
    FSM_STATS mNextFsmStats;
};

C_DISPATH_UT::C_DISPATH_UT()
{
}

C_DISPATH_UT::~C_DISPATH_UT()
{
}

void C_DISPATH_UT::callback_fun(S_DISPATCH_LISTEN_EVENT tmpCurrDispathUt)
{
    //todo main phase

    chgstats(mNextFsmStats);
    chgevent(mNextEventUt);
}

void C_DISPATH_UT::chgstats(FSM_STATS tmpFsmStats)
{
    S_EVENT_UT tmpEventUt;
    tmpEventUt.mStats = tmpFsmStats;
    tmpEventUt.mSchedId = mCurrSchedId;
    m_dispatch.add_que(tmpEventUt);
}

void C_DISPATH_UT::chgevent(S_EVENT_UT tmpEventUt)
{
    m_dispatch.add_que(tmpEventUt);
}
