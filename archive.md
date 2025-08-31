---
layout: default
title: Portfolio Archive
permalink: /archive/
---

# Portfolio Archive

Below are all portfolio items for this course. New posts appear here automatically.

<ul>
{% assign items = site.projects | sort: 'date' | reverse %}
{% for item in items %}
  <li style="margin: 0.75rem 0;">
    <a href="{{ item.url }}"><strong>{{ item.title }}</strong></a><br/>
    <em>{{ item.subtitle }}</em><br/>
    {{ item.description }}
  </li>
{% endfor %}
</ul>
