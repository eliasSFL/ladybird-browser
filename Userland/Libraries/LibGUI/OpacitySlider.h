/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 * Copyright (c) 2022, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/AbstractSlider.h>

namespace GUI {

class OpacitySlider : public AbstractSlider {
    C_OBJECT(OpacitySlider);

public:
    virtual ~OpacitySlider() override = default;

protected:
    virtual void paint_event(PaintEvent&) override;
    virtual void mousedown_event(MouseEvent&) override;
    virtual void mousemove_event(MouseEvent&) override;
    virtual void mouseup_event(MouseEvent&) override;
    virtual void mousewheel_event(MouseEvent&) override;

private:
    explicit OpacitySlider(Gfx::Orientation = Gfx::Orientation::Horizontal);

    Gfx::IntRect frame_inner_rect() const;

    virtual Optional<UISize> calculated_min_size() const override;
    virtual Optional<UISize> calculated_preferred_size() const override;

    int value_at(Gfx::IntPoint) const;

    bool m_dragging { false };
};

}
