---
layout: default
title: Home
---

<div class="hero">
  <h1>Example Web Page</h1>
  <p>I’m Vibha Duraikkannan, an ECE × Art student exploring digital fabrication, interactive systems, and design.</p>
  <a class="btn" href="{{ '/projects/' | relative_url }}">My Projects</a>
</div>

## Featured Projects

<div class="grid">
{% assign featured = site.projects | where: 'featured', true | sort: 'date' | reverse | slice: 0, 3 %}
{% for p in featured %}
  <a class="card" href="{{ p.url | relative_url }}">
    {% if p.thumbnail %}<img src="{{ p.thumbnail | relative_url }}" alt="">{{% endif %}}
    <div class="pad">
      <h3>{{ p.title }}</h3>
      <p>{{ p.teaser | default: p.subtitle | default: p.description }}</p>
    </div>
  </a>
{% endfor %}
</div>
