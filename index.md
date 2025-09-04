---
layout: default
title: Home
---

<div class="hero">
  <h1>Vibha Duraikkannan</h1>
  <p>Vibha Duraikkannan is a third year Vanderbilt student studying Electrical and Computer Engineering and Art. She loves finding ways to bring creativity and technology together. She is passionate about user-centered design, graphic design, and product design. She is always excited to learn, experiment, and grow as a designer!</p>
  <a class="btn" href="{{ '/projects/' | relative_url }}">My Projects</a>
</div>

## Featured Projects

<div class="grid">
{% assign featured = site.projects | where: 'featured', true | sort: 'date' | reverse | slice: 0, 3 %}
{% for p in featured %}
  <a class="card" href="{{ p.url | relative_url }}">
    {% if p.thumbnail %}<img src="{{ p.thumbnail | relative_url }}" alt="">{% endif %}
    <div class="pad">
      <h3>{{ p.title }}</h3>
      <p>{{ p.teaser | default: p.subtitle | default: p.description }}</p>
    </div>
  </a>
{% endfor %}
</div>
