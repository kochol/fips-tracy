#ifndef __TRACYTIMELINEITEMPLOT_HPP__
#define __TRACYTIMELINEITEMPLOT_HPP__

#include "TracyEvent.hpp"
#include "TracyTimelineItem.hpp"

namespace tracy
{

class TimelineItemPlot final : public TimelineItem
{
public:
    TimelineItemPlot( View& view, Worker& worker, PlotData* plot );

protected:
    uint32_t HeaderColor() const override { return 0xFF44DDDD; }
    uint32_t HeaderColorInactive() const override { return 0xFF226E6E; }
    uint32_t HeaderLineColor() const override { return 0x8844DDDD; }
    const char* HeaderLabel() const override;

    int64_t RangeBegin() const override;
    int64_t RangeEnd() const override;

    void HeaderTooltip( const char* label ) const override;
    void HeaderExtraContents( int offset, const ImVec2& wpos, float labelWidth, double pxns, bool hover ) override;

    bool DrawContents( const TimelineContext& ctx, int& offset, bool hover, float yMin, float yMax ) override;

    bool IsEmpty() const override;

private:
    PlotData* m_plot;
};

}

#endif
