class C_DISPATCH
{
public:


    C_DISPATCH();
    C_DISPATCH(C_DISPATCH &&) = default;
    C_DISPATCH(const C_DISPATCH &) = default;
    C_DISPATCH &operator=(C_DISPATCH &&) = default;
    C_DISPATCH &operator=(const C_DISPATCH &) = default;
    ~C_DISPATCH();

    void schedule();
    void notify(S_DISPATCH_LISTENER_EVENT tmp_currdispath_ut);
    void handle_notify(S_DISPATCH_LISTENER_EVENT tmp_currdispath_u);
    void add_que();
    void addListener(C_DISPATCH_UT tmpUt, FSM_STATS tmpStats, int tmpSchedId);

private:
    map<int, C_DISPATCH_UT> m_mont_lisner[FSM_STATS_END];
    vector<S_DISPATCH_LISTENER_EVENT> m_disp_listener_event_que;
};

C_DISPATCH::C_DISPATCH()
{
}

C_DISPATCH::~C_DISPATCH()
{
}

void C_DISPATCH::schedule()
{
    while(m_stimend_flag)
    {
        while(m_disp_listener_event_que.size())
        {
            S_DISPATCH_LISTENER_EVENT tmp_currdispath_ut;

            tmp_currdispath_ut = m_disp_listener_event_que.pop_front();
            notify(tmp_currdispath_ut);
        }
    }
}

void C_DISPATCH::notify(S_DISPATCH_LISTENER_EVENT tmp_currdispath_ut)
{
    FSM_STATS stats=tmp_currdispath_ut.curr.mstats;
    int       schedId = tmp_currdispath_ut.curr.mSchedId
    switch(stats)
    {
        case STIM_START:
        case DRV_FRAME_START:
        case DRV_AGENT:
        case STIM_RM:
        case STIM_RST:
        case DRV_CFG_SOF:
        case DRV_CFG_END:
        case DRV_DATA_SOF:
        case DRV_DATA_END:
        case DRV_FRAME_END:
        case DRV_STIM_END:
        {
            handle_notify();
            break;
        }
        default:
            cout<<"error"<<endl;
    }
}

void C_DISPATCH::handle_notify(S_DISPATCH_LISTENER_EVENT tmp_currdispath_ut);
{
    FSM_STATS stats = tmp_currdispath_ut.curr.mstats;
    int       schedId = tmp_currdispath_ut.curr.mSchedId;
    m_mont_lisner[stats][schedId].callback_fun(tmp_currdispath_ut);
}

void C_DISPATCH::add_que(S_DISPATCH_LISTENER_EVENT tmp_currdispath_ut)
{
    m_disp_listener_event_que.push_back(tmp_currdispath_ut);
}

void C_DISPATCH::(C_DISPATCH_UT tmpUt, FSM_STATS tmpStats, int tmpSchedId)
{
    m_mont_lisner[tmpStats][tmpSchedId] = tmpUt;
}
