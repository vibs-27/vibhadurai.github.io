---
layout: default
title: Projects
permalink: /projects/
---

# Projects

<div class="grid">
{% assign all = site.projects | sort: 'date' | reverse %}
{% for p in all %}
  <a class="card" href="{{ p.url | relative_url }}">
    {% if p.thumbnail %}<img src="{{ p.thumbnail | relative_url }}" alt="">{{% endif %}}
    <div class="pad">
      <h3>{{ p.title }}</h3>
      <p>{{ p.teaser | default: p.subtitle | default: p.description }}</p>
    </div>
  </a>
{% endfor %}
</div>
