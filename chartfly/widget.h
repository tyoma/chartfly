#pragma once

#include <memory>

namespace cf
{
	struct location_context;
	struct graphics_context;

	struct controller
	{
		virtual ~controller() { }
		virtual void mouse_move(const location_context &location, int x, int y) = 0;
		virtual bool mouse_down(const location_context &location, int x, int y, int buttons) = 0;
		virtual void mouse_up(const location_context &location, int x, int y, int buttons) = 0;
		virtual void key_down(const location_context &location, wchar_t c) = 0;
	};

	struct view
	{
		virtual ~view() { }
		virtual bool is_dirty() const = 0;
		virtual void paint(graphics_context &gcontext, const location_context &location) = 0;
	};

	struct widget
	{
		virtual ~widget() { }
		virtual std::shared_ptr<controller> create_controller() = 0;
		virtual std::shared_ptr<view> create_view() = 0;
	};
}
